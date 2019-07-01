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

#define REQ     (1)
#define BUSY    (2)

const uint32 inData[10] = {
    1010002,2009004,3008006,4007008,5006010,
    6005001,7004003,8003005,9002007,10001009};

int main(void) {
    uint32 i, j;
    uint32 result;
    char sbuf[64];
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    UART_PutStringConst("\r\nHELLO WORLD\r\n");
    
    for (j = 0; j < 2; j++) {
        // Clear the accumulator
        ACC_ClearAccumulator();
        
        // Add ten values into accumulator
        for (i = 0; i < (sizeof inData / sizeof *inData); i++) {
            while (!(SR1_Read() & REQ)) ;
            ACC_WriteValue(inData[i]);
        }
        
        // Wait for calculation completed.
        while (SR1_Read() & BUSY) ;
        
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
