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

#if !defined(ACCUMULATOR16_`$INSTANCE_NAME`_H)
#define ACCUMULATOR16_`$INSTANCE_NAME`_H

#include "cyfitter.h"
#include "cytypes.h"

//**************************************************************
//  Function Prototypes
//**************************************************************
void `$INSTANCE_NAME`_WriteValue(uint16 value);
uint16 `$INSTANCE_NAME`_ReadAccumulator(void);
void `$INSTANCE_NAME`_ClearAccumulator(void);

//**************************************************************
//  Registers
//**************************************************************
#define `$INSTANCE_NAME`_INPUT_REG (* (reg16 *) `$INSTANCE_NAME`_dp_u0__16BIT_F0_REG)
#define `$INSTANCE_NAME`_INPUT_PTR (  (reg16 *) `$INSTANCE_NAME`_dp_u0__16BIT_F0_REG)
#define `$INSTANCE_NAME`_ACCUMULATOR_REG (* (reg16 *) `$INSTANCE_NAME`_dp_u0__16BIT_A0_REG)
#define `$INSTANCE_NAME`_ACCUMULATOR_PTR (  (reg16 *) `$INSTANCE_NAME`_dp_u0__16BIT_A0_REG)

#endif  // ACCUMULATOR16_`$INSTANCE_NAME`_H
/* [] END OF FILE */
