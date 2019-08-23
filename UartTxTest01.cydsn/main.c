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

#define SR1_DREQ (1)
#define SR1_SW1  (2)

CYBIT sending = 0;

uint8 packet[6] = {0x0f, 0x33, 0x55, 0xaa, 0x71, 0xff};

volatile CYBIT int_Sample_flag = 0;

CY_ISR(int_Sample_isr) {
    int_Sample_flag = 1;
}

int main(void)
{
    uint32 index = 0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Probe_UART_Start();
    int_Sample_StartEx(int_Sample_isr);

    for(;;)
    {
        /* Place your application code here. */
        if (SR1_Read() & SR1_SW1) {
            // SW1 released
            if (sending) {
                if (index >= sizeof packet) {
                    sending = 0;
                    index = 0;
                }
            }
        } else {
            // SW1 pushed
            if (!sending) {
                sending = 1;
            }
        }
        if (sending) {
            if (index < sizeof packet) {
                if (SR1_Read() & SR1_DREQ) {
                    UartTx_WriteValue(packet[index++]);
                }
            }
        }
        if (int_Sample_flag) {
            int_Sample_flag = 0;
            Probe_UART_PutChar(Probe_Read());
        }
    }
}

/* [] END OF FILE */
