/*
 * UART.h
 *
 * Created: 1/11/2024 4:26:34 PM
 *  Author: XPRISTO
 */ 


#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "bit_math.h"
#define F_CPU 8000000UL

void UART_Init(void);

void UART_Transmit(uint8_t data);

uint8_t UART_Recieve(void);

void UART_SEND_NUM32(uint32_t NUM);

uint32_t UART_RecieveNUM32(void);

void UART_RECIEVE_STR(uint8_t *buff);
void UART_SEND_STR(uint8_t *str);
void UART_SEND_NOBLOCK(uint8_t data);
uint8_t UART_Recieve_NOBLOCK(void);
uint8_t UART_Recieve_PERIODIC_CHECK(uint8_t *ch);

void UART_TX_IRQEnable(void);
void UART_TX_IRQDisable(void);
void UART_RX_IRQEnable(void);
void UART_RX_IRQDisable(void);

void UART_SENDString_Asynch(uint8_t *str);
void UART_RecieveString_Asynch(uint8_t *str);




#endif /* UART_H_ */