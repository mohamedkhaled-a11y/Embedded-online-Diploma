/*
 * STM32F103X6_Drivers.h
 *
 *  Created on: Nov 24, 2023
 *      Author: Mohamed_khaled
 */

#ifndef STM32F103X6_DRIVERS_H_
#define STM32F103X6_DRIVERS_H_

//-----------------------------
//Includes
//-----------------------------

#include "stdint.h"
#include "stdlib.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define     Flash_memory_BASE_Addres               0x08000000UL
#define     SYSTEM_memory_BASE_Addres              0x1FFFF000UL
#define     SRAM_BASE_Addres                       0x20000000UL
#define     PERIPHERALS_BASE_Addres                0x40000000UL
#define     CORTEX_M3_BASE_Addres                  0xE0000000UL

//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------


//----------------Base addresses for AHB BUS Peripherals--------------------------//

#define RCC_BASE                            (PERIPHERALS_BASE_Addres+0x00021000UL)

//----------------Base addresses for ABP2 BUS Peripherals--------------------------//

#define GPIOA_BASE                          (PERIPHERALS_BASE_Addres+0x00010800UL)
#define GPIOB_BASE                          (PERIPHERALS_BASE_Addres+0x00010C00UL)
#define GPIOC_BASE                          (PERIPHERALS_BASE_Addres+0x00011000UL)
#define GPIOD_BASE                          (PERIPHERALS_BASE_Addres+0x00011400UL)

//--------------E IS NOT INCLUDED------------------------//
#define GPIOE_BASE                          (PERIPHERALS_BASE_Addres+0x00011800UL)

#define AFIO_BASE                           (PERIPHERALS_BASE_Addres+0x00010000UL)
#define EXTI_BASE                           (PERIPHERALS_BASE_Addres+0x00010400UL)


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

    volatile uint32_t    CRL;
    volatile uint32_t    CRH;
    volatile uint32_t    IDR;
    volatile uint32_t    ODR;
    volatile uint32_t    BSRR;
    volatile uint32_t    BRR;
    volatile uint32_t    LCKR;
}GPIO_TypeDef;

typedef struct {

    volatile uint32_t   EVCR;
    volatile uint32_t   MAPR;
    volatile uint32_t   EXTICR1;
    volatile uint32_t   EXTRICR2;
    volatile uint32_t   EXTRICR3;
    volatile uint32_t   EXTRICR4;
    volatile uint32_t   RESERVED;
    volatile uint32_t   MAPR2;
}AFIO_TypeDef;


typedef struct {

	volatile uint32_t   CR;
	volatile uint32_t   CFGR;
	volatile uint32_t   CIR;
	volatile uint32_t   APB2RSTR;
	volatile uint32_t   APB1RSTR;
	volatile uint32_t   AHBENR;
	volatile uint32_t   ABP2ENR;
	volatile uint32_t   ABP1ENR;
	volatile uint32_t   BDCR;
	volatile uint32_t   CSR;
	volatile uint32_t   AHBSTR;

}RCC_TypeDef;

typedef struct {

	volatile uint32_t   IMR;
	volatile uint32_t   EMR;
	volatile uint32_t   RTSR;
	volatile uint32_t   FTSR;
	volatile uint32_t   SWIER;
	volatile uint32_t   PR;

}EXTI_TypeDef;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define  GPIOA           ((GPIO_TypeDef *)GPIOA_BASE)

#define  GPIOB           ((GPIO_TypeDef *)GPIOB_BASE)

#define  GPIOC           ((GPIO_TypeDef *)GPIOC_BASE)

#define  GPIOD           ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE            ((GPIO_TypeDef *)GPIOE_BASE)

#define RCC              ((RCC_TypeDef *)RCC_BASE)

#define EXTI             ((EXTI_TypeDef *)EXTI_BASE)

#define AFIO             ((AFIO_TypeDef *)AFIO_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//ENable clk of peripherals

#define RCC_GPIOA_CLK_EN()                (RCC->ABP2ENR |= 1<<2)

#define RCC_GPIOB_CLK_EN()                (RCC->ABP2ENR |= 1<<3)

#define RCC_GPIOC_CLK_EN()                (RCC->ABP2ENR |= 1<<4)

#define RCC_GPIOD_CLK_EN()                (RCC->ABP2ENR |= 1<<5)

#define RCC_GPIOE_CLK_EN()                (RCC->ABP2ENR |= 1<<6)





//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros
//-*-*-*-*-*-*-*-*-*-*-

#define STATE_HIGH                    1
#define STATE_LOW                     0






#endif /* STM32F103X6_DRIVERS_H_ */
