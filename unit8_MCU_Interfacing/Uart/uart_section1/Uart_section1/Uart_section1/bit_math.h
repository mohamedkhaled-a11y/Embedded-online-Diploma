/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  bit_math.h
 *       Module:  lib
 *
 *  Description:  bitwise operations macros      
 *  
 *********************************************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SET_BIT(REG,BIT_NO) 			REG|=(1<<BIT_NO)
#define CLEAR_BIT(REG,BIT_NO) 			REG&=~(1<<BIT_NO)
#define CHECK_BIT(REG,BIT_NO) 			((REG>>BIT_NO)&0x01)
#define FLIP_BIT(REG,BIT_NO)    		REG^=(1<<BIT_NO)
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* BIT_MATH_H */

/**********************************************************************************************************************
 *  END OF FILE: bit_math.h
 *********************************************************************************************************************/
