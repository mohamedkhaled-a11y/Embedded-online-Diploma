/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include "STM32F103X8.h"
#include "stm32f103x8_gpio_driver.h"
#include "stm32f103x8_RCC_driver.h"
#include "stm32f103x8_USART_driver.h"
void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();

	RCC_AFIO_CLK_EN();
}



void delay(int delay)
{
	uint32_t i,j;
	for (i = 0; i < delay; i++)
	{
		for(j = 0; j < 255 ; j++);
	}
}


unsigned char ch;
/*void UART_IRQ_Callback(void)
{
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);

}
*/
int main(void)
{

	UART_Config USARTcfg;

	USARTcfg.BaudRate=UART_BAUD_RATE_115200;
	USARTcfg.HWFLOWCTRL=UART_HWFlow_CTRL_NONE;
	USARTcfg.IRQEnable=UART_IRQ_Enable_NONE;
	USARTcfg.UART_IRQ_CALLBACK=NULL;
	USARTcfg.parity=UART_Parity_None;
	USARTcfg.WordLength=UART_WordLength_8Bits;
	USARTcfg.StopBits=UART_ONE_STOP_Bit;
	USARTcfg.mode=UART_TX_RX_mode;

	MCAL_UART_Init(USART1, &USARTcfg);
	MCAL_UART_GPIO_Set_Pins(USART1);


	while(1)
	{

		MCAL_UART_ReceiveData(USART1, &ch, enable);
		MCAL_UART_SendData(USART1, &ch, enable);


	}
}
