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

void `$INSTANCE_NAME`_WriteValue(uint32 value) {
    `$INSTANCE_NAME`_INPUT_REG = value;
}

uint32 `$INSTANCE_NAME`_ReadAccumulator(void) {
    return `$INSTANCE_NAME`_ACCUMULATOR_REG;
}

void `$INSTANCE_NAME`_ClearAccumulator(void) {
    `$INSTANCE_NAME`_ACCUMULATOR_REG = 0u;
}

/* [] END OF FILE */
