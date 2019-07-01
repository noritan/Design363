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

#if !defined(ACCUMULATOR32_`$INSTANCE_NAME`_H)
#define ACCUMULATOR32_`$INSTANCE_NAME`_H

#include "cyfitter.h"
#include "cytypes.h"

//**************************************************************
//  Function Prototypes
//**************************************************************
void `$INSTANCE_NAME`_WriteValue(uint32 value);
uint32 `$INSTANCE_NAME`_ReadAccumulator(void);
void `$INSTANCE_NAME`_ClearAccumulator(void);

//**************************************************************
//  Registers
//**************************************************************
#define `$INSTANCE_NAME`_INPUT_REG (* (reg32 *) `$INSTANCE_NAME`_dp_u0__F0_REG)
#define `$INSTANCE_NAME`_INPUT_PTR (  (reg32 *) `$INSTANCE_NAME`_dp_u0__F0_REG)
#define `$INSTANCE_NAME`_ACCUMULATOR_REG (* (reg32 *) `$INSTANCE_NAME`_dp_u0__A0_REG)
#define `$INSTANCE_NAME`_ACCUMULATOR_PTR (  (reg32 *) `$INSTANCE_NAME`_dp_u0__A0_REG)

#endif  // ACCUMULATOR32_`$INSTANCE_NAME`_H
/* [] END OF FILE */
