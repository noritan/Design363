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

int main(void)
{
    uint8 i;
    char sbuf[128];
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    UART_PutString("\r\nHELLO WORLD\r\n");
    sprintf(sbuf, "INIT A0=%d, A1=%d\r\n", PR1_ReadA0(), PR1_ReadA1());
    UART_PutString(sbuf);
    
    for (i = 0; i < 10; i++) {
        sprintf(sbuf, "WRITE A0=%d, A1=%d\r\n", i, 9-i);
        UART_PutString(sbuf);
        PR1_WriteA0(i);
        PR1_WriteA1(9-i);
        sprintf(sbuf, "READ A0=%d, A1=%d\r\n", PR1_ReadA0(), PR1_ReadA1());
        UART_PutString(sbuf);
    }    

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
