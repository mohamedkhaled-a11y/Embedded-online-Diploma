/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>

// Define CLOCK


#define RCC_BASE             0x40021000
#define RCC_ABP2ENR         *(volatile unsigned int *)(RCC_BASE+0x18)
#define RCC_IOPEN             (1<<2)




// DEFINE EXT INTERRUPTS
#define EXT_BASE             0x40010400

#define EXT_IMR0             *(volatile unsigned int *)(EXT_BASE+0x0)
#define EXT_RTST             *(volatile unsigned int *)(EXT_BASE+0x08)
#define EXT_PR               *(volatile unsigned int *)(EXT_BASE+0x14)



//DEFINE GPIO
#define GPIOA_BASE             0x40010800

#define GPIOA_CRH              *(volatile unsigned int *)(GPIOA_BASE+0x04)
#define GPIOA_CRL             *(volatile unsigned int *)(GPIOA_BASE+0x00)
#define GPIOA_ODR             *(volatile unsigned int *)(GPIOA_BASE+0x0C)
#define GPIO_P13               (1UL<<13)
//Define AFIO for mapping port

#define AFIO_BASE             0x40010000
#define AFIO_EXTICR1         *(volatile unsigned int *)(AFIO_BASE+0x08)

//Define NVIC

#define NVIC_ISR_E0           *(volatile unsigned int *)(0xE000E100)


void clk_init()
{

	RCC_ABP2ENR |= RCC_IOPEN;

	RCC_ABP2ENR |= (1<<0);
}

void GPIO_init()

{

  GPIOA_CRH &=0xFF0FFFFF;
  GPIOA_CRH |=0x00200000;

  //configure PIN A0 as a floating pin
  GPIOA_CRL |= (1<<2);


}





int main(void)
{
	clk_init();
	GPIO_init();

	EXT_IMR0 |=(1<<0);
	EXT_RTST |=(1<<0);
	AFIO_EXTICR1 =0;
	NVIC_ISR_E0 |=(1<<6);


	while(1);

}





void EXTI0_IRQHandler()
{

	GPIOA_ODR ^=(1<<13);
	//clear pending register
	EXT_PR |=(1<<0);

}




