/*
 * STM32F103x8_gpio_driver.h
 *
 *  Created on: Nov 24, 2023
 *      Author: Mohamed_khaled
 */

#ifndef STM32F103X8_GPIO_DRIVER_H_
#define STM32F103X8_GPIO_DRIVER_H_

//-----------------------------
//Includes
#include "STM32F103X6_Drivers.h"

//-----------------------------

//-----------------------------
//User type definitions (structures)

typedef struct {

	uint16_t       PIN_NUM;            // this parameter must be selected from @ref GPIO_PIN_NUM  Macros

	uint8_t       GPIO_Mode;           // this parameter must be selected from @ref GPIO_Mode_  Macros

	uint8_t       GPIO_Speed;          // this parameter must be selected from @ref GPIO_Speed_  Macros


}GPIO_PIN_conf_t;



//-----------------------------

//-----------------------------
//Macros Configuration References


#define      GPIO_PIN_RESET           0
#define      GPIO_PIN_SET             1


#define     GPIO_RETURN_LOCK_Enabled    1
#define     GPIO_RETURN_LOCK_Disabled   0


/* GPIO_PIN_NUM Macros*/
/*NOTE: pin numbers in dec is shifted in HEX*/

#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define GPIO_PIN_ALL               ((uint16_t)0xFFFFu)

#define GPIO_PIN_MASK              0x0000FFFF


//-----------------------------

/*GPIO_PIN_MODES*/
/*
In input mode (MODE[1:0]=00):
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
In output mode (MODE[1:0] > 00):
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input             ==Floating_input
*/

#define GPIO_Analog_inp_mode               0x00000000u
#define GPIO_Float_inp_mode                0x00000001u
#define GPIO_INP_PUP_mode                  0x00000002u
#define GPIO_INP_PD_mode                   0x00000003u

#define GPIO_OUT_PP_mode                   0x00000004u
#define GPIO_OUT_OD_mode                   0x00000005u
#define GPIO_AFIO_OUT_PP_mode              0x00000006u
#define GPIO_AFIO_OUT_OD_mode              0x00000007u

#define GPIO_AFIO_INP                      0x00000008u


/*GPIO_OUT_SPEED MODE*/

/*01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz.*/

#define  GPIO_SPEED_10M                    0x00000001u   //Output mode, max speed 10 MHz
#define  GPIO_SPEED_2M                     0x00000002u   //Output mode, max speed 2 MHz
#define  GPIO_SPEED_50M                    0x00000003u   //Output mode, max speed 50 MHz




/*@ref Module_REF_NAME_define
*/
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOX, GPIO_PIN_conf_t *GPIO_PinCfg);
void MCAL_GPIO_DEInit(GPIO_TypeDef *GPIOX);
uint8_t MCAL_GPIO_Read_PIN(GPIO_TypeDef *GPIOX, uint16_t pinNumber);




#endif /* STM32F103X8_GPIO_DRIVER_H_ */
