/*
 * stm32f103x8_gpio_driver.h
 *      Author: Mohamed khaled
 *      Mastering Embedded System Online Diploma
 *
 */

#ifndef STM32F103X8_USART_DRIVER_H_
#define STM32F103X8_USART_DRIVER_H_

//includes
#include "STM32F103x8.h"
#include "stm32f103x8_gpio_driver.h"
#include "stm32f103x8_RCC_driver.h"


// config parameters
typedef struct {

	uint8_t mode ;                    /*specifies the TX/RX Mode select ,
	                                   this parameter should be selected from @macros modes (TX,RX TX/RX)*/

	uint32_t BaudRate;                 /*Specifies BaudRate
	                                    this parameter should be selected from @macros BaudRates (9600,115200 (recomended),....)*/

	uint16_t WordLength;               /*specifies Payload length (Stop bits , data bits)
	                                    this parameter should be selected from @macros wordLength*/

	uint8_t parity;                      /*specfies parity bits (Even,ODD)
	                                     this parameter should be selected from @macros paritySelection*/

	uint8_t StopBits;                    /*specfies stopBits
	                                      this parameter should be selected from @macros stopBitsSelection*/

	uint8_t HWFLOWCTRL;                   /*specfies Hardware flow control
	                                      this parameter should be selected from @macros RTS/CTS Selection*/

	uint8_t IRQEnable;                    /*specfies Enable of IRQ
	                                      this parameter should be selected from @macros IRQ Enable/Disable*/

	void (*UART_IRQ_CALLBACK )(void);     /*specfies call back function from APP*/



}UART_Config;



/* macros of selecting mode*/

#define UART_TX_Mode                 (uint32_t)(1<<3)     //TE=1
#define UART_RX_Mode                 (uint32_t)(1<<2)    //RE=1
#define UART_TX_RX_mode              ((uint32_t)(1<<2 | 1<<3))    //RE=1



//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
// uint32((100 *fclk ) / (16 * Baudrate) == (25 *fclk ) / (4* Baudrate) )
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV  )  * 100
//DIV_Mantissa = Integer Part (USARTDIV  )
//DIV_Fraction = (( USARTDIV_MUL100  - DIV_Mantissa_MUL100  ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)						(uint32_t) ( (25 * _PCLK_ ) / (4  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)						(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)							(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)						(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)					(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )



/*BaudRate select*/

#define UART_BAUD_RATE_2400                      2400
#define UART_BAUD_RATE_9600                      9600
#define UART_BAUD_RATE_19200                     19200
#define UART_BAUD_RATE_57600                     57600
#define UART_BAUD_RATE_115200                    115200
#define UART_BAUD_RATE_230400                    230400
#define UART_BAUD_RATE_460800                    460800
#define UART_BAUD_RATE_921600                    921600
#define UART_BAUD_RATE_225000                    225000
#define UART_BAUD_RATE_450000                    450000



/* WOrdLength (payloadLength)*/

#define UART_WordLength_8Bits                     ( uint32_t)(0)
#define UART_WordLength_9Bits                     ( uint32_t)(1<<12)


/*Parity Selection*/


#define UART_Parity_None                          ( uint32_t)(0)
#define UART_Parity_EVEN                          ( uint32_t)(1<<10)
#define UART_Parity_ODD                           ( uint32_t)(1<<10 | 1<<9)


/*STOP Bits Selection
 * Bits 13:12 STOP: STOP bits
These bits are used for programming the stop bits.
00: 1 Stop bit
01: 0.5 Stop bit
10: 2 Stop bits
11: 1.5 Stop bit*/

#define UART_ONE_STOP_Bit                          (uint32_t)(0)
#define UART_HALF_STOP_Bit                         (uint32_t)(1<<12)
#define UART_TWO_STOP_BitS                         (uint32_t)(2<<12)
#define UART_ONE_Half_STOP_Bit                     (uint32_t)(3<<12)



/*Hardware flow control */

#define UART_HWFlow_CTRL_NONE                           (uint32_t)(0)
#define UART_HWFlow_CTRL_RTS                            (uint32_t)(1<<8)
#define UART_HWFlow_CTRL_CTS                            (uint32_t)(1<<9)
#define UART_HWFlow_CTRL_RTS_CTS                        ((uint32_t)(1<<8 | 1<<9))

/*IRQ_Enable Select*/

#define UART_IRQ_Enable_NONE                              (uint32_t)(0)
#define UART_IRQ_Enable_TXE                               (uint32_t)(1<<7)        //transmit data reg empty
#define UART_IRQ_Enable_TC                                (uint32_t)(1<<6)       // transmit complete
#define UART_IRQ_Enable_RXNEIE                            (uint32_t)(1<<5)      // Recieved data ready to be read & Over run detected
#define UART_IRQ_Enable_PE                            (uint32_t)(1<<8)      //parity error

enum Polling_mechism{
	enable ,
	disable
};


/*
 *
 *
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */


/* Initialization/de-initialization functions  **********************************/


void MCAL_UART_Init (USART_TypeDef *USARTx, UART_Config* UART_Conf);
void MCAL_UART_DeInit (USART_TypeDef *USARTx);


void MCAL_UART_GPIO_Set_Pins (USART_TypeDef *USARTx);


void MCAL_UART_SendData	(USART_TypeDef *USARTx, uint16_t *pTxBuffer,enum Polling_mechism PollingEn );
void MCAL_UART_ReceiveData	(USART_TypeDef *USARTx, uint16_t *pTxBuffer ,enum Polling_mechism PollingEn );

void MCAL_UART_WAIT_TC (USART_TypeDef *USARTx ) ;







#endif /* STM32F103X8_USART_DRIVER_H_ */
























