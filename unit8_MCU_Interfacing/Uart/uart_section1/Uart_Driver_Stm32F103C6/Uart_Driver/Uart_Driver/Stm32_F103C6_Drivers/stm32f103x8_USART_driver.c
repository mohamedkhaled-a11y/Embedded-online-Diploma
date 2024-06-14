
/*
 * stm32f103x8_gpio_driver.h
 *      Author: Mohamed khaled
 *      Mastering Embedded System Online Diploma
 *
 */

#include "stm32f103x8_USART_driver.h"



/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */
UART_Config* Global_UART_Config  = NULL ;

/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */


/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */

/**================================================================
 * @Fn				-MCAL_UART_Init
 * @brief 			- Initializes UART (Supported feature ASYNCH. Only)
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @param [in] 		- UART_Config: All UART Configuration EXTI_PinConfig_t
 * @retval 			-none
 * Note				-Support for Now Asynch mode & Clock 8 MHZ S
 */
void MCAL_UART_Init (USART_TypeDef *USARTx, UART_Config* UART_Conf)
{
	Global_UART_Config=UART_Conf;

	uint32_t Pclk , BRR;

	//Enable UART CLOCK

	if(USARTx==USART1)
	{
		RCC_USART1_CLK_EN();
	}
	else if(USARTx==USART2)
		{
			RCC_USART2_CLK_EN();
		}

	else if(USARTx==USART3)
		{
			RCC_USART3_CLK_EN();
		}


	//Enable UE BIT
	USARTx->CR1 |=(1<<13);

	//Select word Length
	USARTx->CR1 |= UART_Conf->WordLength;

	//Mode select
	USARTx->CR1 |= UART_Conf->mode;

	//set parity
	USARTx->CR1 |= UART_Conf->parity;

	//Stop bits
	USARTx->CR2 |= UART_Conf->StopBits;

	//Hardware flow control

	USARTx->CR3 |= UART_Conf->HWFLOWCTRL;

	//Set Baud Rate
	//check for uart

	if(USARTx==USART1)
	{
		Pclk=MCAL_RCC_GetPCLK2Freq();
	}
	else
	{
		Pclk=MCAL_RCC_GetPCLK1Freq();
	}

	BRR=UART_BRR_Register(Pclk,UART_Conf->BaudRate);

	USARTx->BRR=BRR;


   //Enable IRQ

	if(UART_Conf->IRQEnable != UART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= (UART_Conf->IRQEnable);

		if(USARTx==USART1)
			NVIC_IRQ37_USART1_Enable;
		else if(USARTx==USART2)
			NVIC_IRQ38_USART2_Enable;
		else if(USARTx==USART3)
					NVIC_IRQ39_USART3_Enable;
	}





}
void MCAL_UART_DeInit (USART_TypeDef *USARTx)
{
    if(USARTx==USART1)
    {
    	RCC_USART1_Reset();
    	NVIC_IRQ37_USART1_Disable;
    }

    else if(USARTx==USART2)
        {
        	RCC_USART2_Reset();
        	NVIC_IRQ38_USART2_Disable;
        }
    if(USARTx==USART3)
        {
        	RCC_USART3_Reset();
        	NVIC_IRQ39_USART3_Disable;
        }





}

void MCAL_UART_SendData	(USART_TypeDef *USARTx, uint16_t *pTxBuffer,enum Polling_mechism PollingEn )
{

	if(PollingEn==enable)
	{
		while(! (USARTx->SR & 1<<7) );
	}

	if(Global_UART_Config->WordLength == UART_WordLength_9Bits)
	{
		USARTx->DR = (*pTxBuffer & (uint16_t)0x01FF);
	}
	else
	{
		USARTx->DR = (*pTxBuffer & (uint8_t)0xFF);
	}



}

void MCAL_UART_ReceiveData	(USART_TypeDef *USARTx, uint16_t *pTxBuffer ,enum Polling_mechism PollingEn )
{
	if(PollingEn==enable)
	{
		while(! (USARTx->SR & 1<<5) );
	}

	if(Global_UART_Config->WordLength == UART_WordLength_9Bits)
	{
		if(Global_UART_Config->parity==UART_Parity_None)
		{

		 *((uint16_t *)pTxBuffer) =USARTx->DR  ;

		}
		else
		{
			*((uint16_t *)pTxBuffer) = (USARTx->DR & (uint8_t)0xff) ;
		}
	}
	else
	{
		if(Global_UART_Config->parity==UART_Parity_None)
				{

				 *((uint16_t *)pTxBuffer) =(USARTx->DR  & (uint8_t)0xff);

				}
				else
				{
					*((uint16_t *)pTxBuffer) = (USARTx->DR & (uint8_t)0x7f) ;
				}

	}


}

void MCAL_UART_WAIT_TC (USART_TypeDef *USARTx )
{

   while(!(USARTx->SR & (1<<6)));

}




void MCAL_UART_GPIO_Set_Pins (USART_TypeDef *USARTx)
{

	GPIO_PinConfig_t GPIOPincfg;
	if(USARTx==USART1)
	{
		//PA9 TX ALT PP
		GPIOPincfg.GPIO_PinNumber=GPIO_PIN_9;
		GPIOPincfg.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
		GPIOPincfg.GPIO_Output_Speed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &GPIOPincfg);

		//PA10 RX
		GPIOPincfg.GPIO_PinNumber=GPIO_PIN_10;
		GPIOPincfg.GPIO_MODE=GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &GPIOPincfg);

		if(Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_CTS || Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS_CTS )
		{
			GPIOPincfg.GPIO_PinNumber=GPIO_PIN_12;
			GPIOPincfg.GPIO_MODE=GPIO_MODE_AF_INPUT;
			MCAL_GPIO_Init(GPIOA, &GPIOPincfg);
		}

		if(Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS || Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS_CTS )
				{
					GPIOPincfg.GPIO_PinNumber=GPIO_PIN_11;
					GPIOPincfg.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
					GPIOPincfg.GPIO_Output_Speed=GPIO_SPEED_10M;
					MCAL_GPIO_Init(GPIOA, &GPIOPincfg);
				}


	}

	else if(USARTx==USART2)
		{
			//PA2 TX ALT PP
			GPIOPincfg.GPIO_PinNumber=GPIO_PIN_2;
			GPIOPincfg.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			GPIOPincfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIOPincfg);

			//PA3 RX
			GPIOPincfg.GPIO_PinNumber=GPIO_PIN_3;
			GPIOPincfg.GPIO_MODE=GPIO_MODE_AF_INPUT;
			MCAL_GPIO_Init(GPIOA, &GPIOPincfg);

			if(Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_CTS || Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS_CTS )
			{
				GPIOPincfg.GPIO_PinNumber=GPIO_PIN_0;
				GPIOPincfg.GPIO_MODE=GPIO_MODE_AF_INPUT;
				MCAL_GPIO_Init(GPIOA, &GPIOPincfg);
			}

			if(Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS || Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS_CTS )
					{
						GPIOPincfg.GPIO_PinNumber=GPIO_PIN_1;
						GPIOPincfg.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
						GPIOPincfg.GPIO_Output_Speed=GPIO_SPEED_10M;
						MCAL_GPIO_Init(GPIOA, &GPIOPincfg);
					}


		}

	else if(USARTx==USART3)
		{
			//PB10 TX ALT PP
			GPIOPincfg.GPIO_PinNumber=GPIO_PIN_10;
			GPIOPincfg.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			GPIOPincfg.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &GPIOPincfg);

			//PB11 RX
			GPIOPincfg.GPIO_PinNumber=GPIO_PIN_11;
			GPIOPincfg.GPIO_MODE=GPIO_MODE_AF_INPUT;
			MCAL_GPIO_Init(GPIOB, &GPIOPincfg);

			if(Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_CTS || Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS_CTS )
			{
				GPIOPincfg.GPIO_PinNumber=GPIO_PIN_13;
				GPIOPincfg.GPIO_MODE=GPIO_MODE_AF_INPUT;
				MCAL_GPIO_Init(GPIOB, &GPIOPincfg);
			}

			if(Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS || Global_UART_Config->HWFLOWCTRL== UART_HWFlow_CTRL_RTS_CTS )
					{
						GPIOPincfg.GPIO_PinNumber=GPIO_PIN_14;
						GPIOPincfg.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
						GPIOPincfg.GPIO_Output_Speed=GPIO_SPEED_10M;
						MCAL_GPIO_Init(GPIOB, &GPIOPincfg);
					}


		}






}


void USART1_IRQHandler(void)
{

  Global_UART_Config->UART_IRQ_CALLBACK();

}

void USART2_IRQHandler(void)
{

  Global_UART_Config->UART_IRQ_CALLBACK();

}

void USART3_IRQHandler(void)
{

  Global_UART_Config->UART_IRQ_CALLBACK();

}
