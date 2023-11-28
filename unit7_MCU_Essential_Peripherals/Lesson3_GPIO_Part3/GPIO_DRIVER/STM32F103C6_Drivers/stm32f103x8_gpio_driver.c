/*
 * stm32f103x8_gpio_driver.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Mohamed_kahled
 */

#include "STM32F103x8_gpio_driver.h"



uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0 ;
		break ;
	case GPIO_PIN_1:
		return 4 ;
		break ;

	case GPIO_PIN_2:
		return 8 ;
		break ;

	case GPIO_PIN_3:
		return 12 ;
		break ;

	case GPIO_PIN_4:
		return 16 ;
		break ;


	case GPIO_PIN_5:
		return 20 ;
		break ;

	case GPIO_PIN_6:
		return 24 ;
		break ;

	case GPIO_PIN_7:
		return 28 ;
		break ;

	case GPIO_PIN_8:
		return 0 ;
		break ;
	case GPIO_PIN_9:
		return 4 ;
		break ;

	case GPIO_PIN_10:
		return 8 ;
		break ;

	case GPIO_PIN_11:
		return 12 ;
		break ;

	case GPIO_PIN_12:
		return 16 ;
		break ;


	case GPIO_PIN_13:
		return 20 ;
		break ;

	case GPIO_PIN_14:
		return 24 ;
		break ;

	case GPIO_PIN_15:
		return 28 ;
		break ;


	}
	return 0 ;

}


/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			- Initializes the GPIOx peripheral according to the specified parameters in the PinConfig
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinConfig: pointer to a GPIO_PinConfig_t structure that contains
 *         						 the configuration information for the specified GPIO peripheral.
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 */

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOX, GPIO_PIN_conf_t *GPIO_PinCfg)
{
	// determine CRL OR CRH
	volatile uint32_t *Config_reg = NULL;
	uint8_t pincfg=0;
	Config_reg = (GPIO_PinCfg->PIN_NUM>GPIO_PIN_8)? &GPIOX->CRH: &GPIOX->CRL;

	//CNF0[1:0] MODE0[1:0=]   Clear the four Bits
	(*Config_reg) &=~(0xF << Get_CRLH_Position(GPIO_PinCfg->PIN_NUM));

	//if Pin is output
	if((GPIO_PinCfg->GPIO_Mode==GPIO_OUT_OD_mode)||(GPIO_PinCfg->GPIO_Mode==GPIO_OUT_PP_mode)||(GPIO_PinCfg->GPIO_Mode==GPIO_AFIO_OUT_OD_mode)||(GPIO_PinCfg->GPIO_Mode==GPIO_AFIO_OUT_PP_mode))
	{
		pincfg= ( ( ( (GPIO_PinCfg->GPIO_Mode-4) <<2 ) | GPIO_PinCfg->GPIO_Speed)& 0x0F );  // CNF0[1:0]= ((MODE-4)<<2) & MODE0[1:0]= |SPEED

	}
	else
	{
		if((GPIO_PinCfg->GPIO_Mode==GPIO_Analog_inp_mode) || (GPIO_PinCfg->GPIO_Mode==GPIO_Float_inp_mode))
		{
			pincfg= ((((GPIO_PinCfg->GPIO_Mode-4) <<2 ) | (0x0)) & (0x0F));
		}
		else if (GPIO_PinCfg->GPIO_Mode==GPIO_AFIO_INP)             //consider AFIO AS FLOATING INP
		{

			pincfg= ((((GPIO_Float_inp_mode-4) <<2 ) | (0x0)) & 0x0F);
		}

		else
		{
			pincfg= ((((GPIO_INP_PUP_mode-4) <<2 ) |(0x0) ) & 0x0F);
			if (GPIO_PinCfg->GPIO_Mode==GPIO_INP_PUP_mode)
			{
				GPIOX->ODR |= GPIO_PinCfg->PIN_NUM;
			}
			else {
				GPIOX->ODR &= ~(GPIO_PinCfg->PIN_NUM);
			}
		}

	}

	(*Config_reg) |= (pincfg<<Get_CRLH_Position(GPIO_PinCfg->PIN_NUM) );

}


/**================================================================
 * @Fn					-MCAL_GPIO_DeInit
 * @brief 				- reset all the GPIO Registers
 * @param [in] 			-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval 				-none
 * Note					-none

 */

void MCAL_GPIO_DEInit(GPIO_TypeDef *GPIOx)
{
	/*
		GPIOx->BRR = 0x00000000 ;
		GPIOx->BSRR =0x00000000 ;
		GPIOx->CRH = 0x44444444 ;
		GPIOx->CRL =  0x44444444 ;
	//	GPIOx->IDR = ;  (READ Only)
		GPIOx->LCKR =  0x00000000 ;
		GPIOx->ODR = 0x00000000;
	 */

	//or you can use the reset Controller
	//APB2 peripheral reset register (RCC_APB2RSTR)
	//Set and cleared by software.

	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);  //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);

	}else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);  //Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);

	}else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);  //Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);

	}else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);  //Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);

	}else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);  //Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);

	}


}

/**================================================================
 * @Fn					-MCAL_GPIO_ReadPin
 * @brief 				-Reads the specified input port pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 				-The input port pin value.
 * Not
 */

uint8_t MCAL_GPIO_Read_PIN(GPIO_TypeDef *GPIOX, uint16_t pinNumber)
{

	uint8_t bit_status=0;

	if((GPIOX->IDR & pinNumber)!=(uint32_t)GPIO_PIN_RESET)
	{
		bit_status=GPIO_PIN_SET;
	}
	else
	{
		bit_status=GPIO_PIN_RESET;
	}

	return bit_status;
}

/**================================================================
 * @Fn					-MCAL_GPIO_ReadPort
 * @brief 				-read the input port VALUE
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-the input port VALUE
 * Note					-none
 */
uint16_t MCAL_GPIO_ReadPort		(GPIO_TypeDef *GPIOx)
{
	uint16_t port_value ;
	port_value = (uint16_t)(GPIOx->IDR) ;
	return port_value ;
}


/**================================================================
 * @Fn					-MCAL_GPIO_WritePort
 * @brief 				-write on output port
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 				-none
 * Note					-none
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx , uint16_t Value)
{

	GPIOx->ODR = (uint32_t)(Value);
}

/**================================================================
 * @Fn					-MCAL_GPIO_WritePin
 * @brief 				-write on specific input pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 *@param [in] 			-Value: Pin Value
 *
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_WritePin	(GPIO_TypeDef *GPIOx , uint16_t PinNumber, uint8_t Value)
{
	if (Value != GPIO_PIN_RESET)
	{
		//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Set the corresponding ODRx bit
		GPIOx->BSRR = PinNumber;

		//		or
		//		GPIOx->ODR |= PinNumber ;
	}
	else
	{
		//		BRy: Port x Reset bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber ;

		//		or
		//		GPIOx->ODR &= ~(PinNumber) ;
	}

}

/**================================================================
 * @Fn					-MCAL_GPIO_TogglePin
 * @brief 				-Toggles the specified GPIO pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 			-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_TogglePin		(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}

/**================================================================
 * @Fn					-MCAL_GPIO_LockPin
 * @brief 				-The locking mechanism allows the IO configuration to be frozen
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in] 		-PinNumber: specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			-Ok if pin Config is locked Or ERROR if pin  not locked
 * Note				-none
 */
uint8_t MCAL_GPIO_LockPin	(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	//	This register is used to lock the configuration of the port bits when a correct write sequence
	//	is applied to bit 16 (LCKK). The value of bits [15:0] is used to lock the configuration of the
	//	GPIO. During the write sequence, the value of LCKR[15:0] must not change. When the
	//	LOCK sequence has been applied on a port bit it is no longer possible to modify the value of
	//	the port bit until the next reset.
	//	Each lock bit freezes the corresponding 4 bits of the control register (CRL, CRH)

	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)


	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked
	//------------------------------------------------

	//	Bit 16 LCKK[16]: Lock key

	volatile uint32_t tmp= (1<<16);

	// BIT 16 in LCKK is 1 and pin value is set
	tmp |= PinNumber;

	// write 1
	GPIOx->LCKR= tmp;

	//write 0
	GPIOx->LCKR =PinNumber;
	//write 1
	GPIOx->LCKR= tmp;
	//read 0
	tmp=GPIOx->LCKR;

	//read one
	if ((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_Enabled;

	}
	else
	{
		return GPIO_RETURN_LOCK_Disabled	;

	}

}
