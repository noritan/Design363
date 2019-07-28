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
#include "`$INSTANCE_NAME`.h"

uint8 `$INSTANCE_NAME`_ReadA0(void) {
    return CY_GET_REG8(`$INSTANCE_NAME`_A0_PTR);
}
void `$INSTANCE_NAME`_WriteA0(uint8 value) {
    CY_SET_REG8(`$INSTANCE_NAME`_A0_PTR, value);
}

uint8 `$INSTANCE_NAME`_ReadA1(void) {
    return CY_GET_REG8(`$INSTANCE_NAME`_A1_PTR);
}
void `$INSTANCE_NAME`_WriteA1(uint8 value) {
    CY_SET_REG8(`$INSTANCE_NAME`_A1_PTR, value);
}

/* [] END OF FILE */
