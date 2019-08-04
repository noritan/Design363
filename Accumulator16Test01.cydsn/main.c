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
#include <stdio.h>

// Flag bit definition of SR1
#define SR1_REQ     (1)

// Data to be sent to Accumulator
const uint16 inData[10] = {1010,2009,3008,4007,5006,6005,7004,8003,9002,10001};
#define DATA_SIZE   (sizeof inData / sizeof *inData)

// Defines for DMA
#define DMA_BYTES_PER_BURST 2
#define DMA_REQUEST_PER_BURST 1
#define DMA_SRC_BASE (CYDEV_FLASH_BASE)
#define DMA_DST_BASE (CYDEV_PERIPH_BASE)

// Variable declarations for DMA
uint8 DMA_Chan;
uint8 DMA_TD[1];

// Accumulator Ready Detection
CYBIT   int_Ready_Flag = 0;

CY_ISR(int_Ready_isr) {
    int_Ready_Flag = 1;
}

int main(void) {
    uint32 i, j;
    uint32 result;
    char sbuf[64];
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    // Initialize UART
    UART_Start();
    UART_PutStringConst("\r\nHELLO WORLD\r\n");
    
    // DMA Configuration
    DMA_Chan = DMA_DmaInitialize(
        DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
        HI16(DMA_SRC_BASE), HI16(DMA_DST_BASE)
    );
    DMA_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(
        DMA_TD[0],
        sizeof inData, CY_DMA_DISABLE_TD, CY_DMA_TD_INC_SRC_ADR
    );
    CyDmaTdSetAddress(DMA_TD[0], LO16((uint32)inData), LO16((uint32)ACC_INPUT_PTR));
    CyDmaChSetInitialTd(DMA_Chan, DMA_TD[0]);
    
    // Initialize Ready interrupt
    int_Ready_ClearPending();
    int_Ready_StartEx(int_Ready_isr);
    
    UART_PutStringConst("DMA Input\r\n");

    for (j = 0; j < 2; j++) {
        // Clear the accumulator
        ACC_ClearAccumulator();

        // Trigger DMA
        CyDmaChEnable(DMA_Chan, 1);

        // Wait for calculation completed.
        while (!int_Ready_Flag) ;
        int_Ready_Flag = 0;
        
        // Get the calculation result
        result = ACC_ReadAccumulator();
        
        // Show the calculation result
        sprintf(sbuf, "ACC=%ld\r\n", result);
        UART_PutString(sbuf);
    }
    
    UART_PutStringConst("Manual Input\r\n");

    for (j = 0; j < 2; j++) {
        // Clear the accumulator
        ACC_ClearAccumulator();
        
        // Add ten values into accumulator
        for (i = 0; i < DATA_SIZE; i++) {
            while (!(SR1_Read() & SR1_REQ)) ;
            ACC_WriteValue(inData[i]);
        }
        
        // Wait for calculation completed.
        while (!int_Ready_Flag) ;
        int_Ready_Flag = 0;
        
        // Get the calculation result
        result = ACC_ReadAccumulator();
        
        // Show the calculation result
        sprintf(sbuf, "ACC=%ld\r\n", result);
        UART_PutString(sbuf);
    }
    
    for(;;) {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
