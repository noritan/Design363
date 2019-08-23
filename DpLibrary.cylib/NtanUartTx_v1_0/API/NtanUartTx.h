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

#if !defined(NTANUARTTX_`$INSTANCE_NAME`_H)
#define NTANUARTTX_`$INSTANCE_NAME`_H
    
#include <cytypes.h>

#define `$INSTANCE_NAME`_INPUT_REG (* (reg8 *)`$INSTANCE_NAME`_dp__F0_REG)
#define `$INSTANCE_NAME`_INPUT_PTR (  (reg8 *)`$INSTANCE_NAME`_dp__F0_REG)

extern void `$INSTANCE_NAME`_WriteValue(uint8 value);

#endif // NTANUARTTX_`$INSTANCE_NAME`_H

/* [] END OF FILE */
