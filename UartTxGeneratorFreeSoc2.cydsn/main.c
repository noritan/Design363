/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

// Statemachine declaration
#define ST_IDLE (0)
#define ST_SEND (1)
#define ST_WAIT (2)

uint32 state = ST_IDLE;

// Data packet to be sent
uint8 packet[128];

// Defines for DMA_UartTx
#define DMA_UartTx_BYTES_PER_BURST 1
#define DMA_UartTx_REQUEST_PER_BURST 1
#define DMA_UartTx_SRC_BASE (CYDEV_SRAM_BASE)
#define DMA_UartTx_DST_BASE (CYDEV_PERIPH_BASE)

// Variable declarations for DMA_UartTx
// Move these variable declarations to the top of the function
uint8 DMA_UartTx_Chan;
uint8 DMA_UartTx_TD[1];

// The main-loop
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    // Initialize the statemachine task
    state = ST_IDLE;

    // DMA Configuration for DMA_UartTx
    DMA_UartTx_Chan = DMA_UartTx_DmaInitialize(
        DMA_UartTx_BYTES_PER_BURST, DMA_UartTx_REQUEST_PER_BURST, 
        HI16(DMA_UartTx_SRC_BASE), HI16(DMA_UartTx_DST_BASE));
    DMA_UartTx_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_UartTx_TD[0], sizeof packet, CY_DMA_DISABLE_TD, CY_DMA_TD_INC_SRC_ADR);
    CyDmaTdSetAddress(DMA_UartTx_TD[0], LO16((uint32)packet), LO16((uint32)UartTx_INPUT_PTR));
    CyDmaChSetInitialTd(DMA_UartTx_Chan, DMA_UartTx_TD[0]);

    // Initialize the packet[]
    // Copy the phrase[] into packet[] as possible
    for (uint32 k = 0; k < sizeof packet; k++) {
        packet[k] = 0x20 + (k & 0x3F);
    }

    for(;;)
    {
        // Statemachine dispatcher
        switch (state) {
            case ST_IDLE:
                // Wait for the SW1 pushed
                if (!Pin_BTN_Read()) {
                    // SW1 pushed
                    CyDmaChEnable(DMA_UartTx_Chan, 1);
                    state = ST_SEND;
                }
                break;
            case ST_SEND:
                // Send a packet until exhausted
                {
                    uint8 dmaState;
                    CyDmaChStatus(DMA_UartTx_Chan, NULL, &dmaState);
                    if (!(dmaState & CY_DMA_STATUS_CHAIN_ACTIVE)) {
                        state = ST_WAIT;
                    }
                }
                break;
            case ST_WAIT:
                // Wait for the SW1 released
                if (Pin_BTN_Read()) {
                    state = ST_IDLE;
                }
                break;
            default:
                state = ST_IDLE;
        }
    }
}

/* [] END OF FILE */
