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

#if !defined(`$INSTANCE_NAME`_H)
#define `$INSTANCE_NAME`_H
    
#include <cytypes.h>

#define `$INSTANCE_NAME`_A0_PTR ((reg8 *)`$INSTANCE_NAME`_dp__A0_REG)
#define `$INSTANCE_NAME`_A1_PTR ((reg8 *)`$INSTANCE_NAME`_dp__A1_REG)
#define `$INSTANCE_NAME`_D0_PTR ((reg8 *)`$INSTANCE_NAME`_dp__D0_REG)
#define `$INSTANCE_NAME`_D1_PTR ((reg8 *)`$INSTANCE_NAME`_dp__D1_REG)

extern uint8 `$INSTANCE_NAME`_ReadA0(void);
extern void `$INSTANCE_NAME`_WriteA0(uint8 value);
extern uint8 `$INSTANCE_NAME`_ReadA1(void);
extern void `$INSTANCE_NAME`_WriteA1(uint8 value);

#endif // `$INSTANCE_NAME`_H

/* [] END OF FILE */
