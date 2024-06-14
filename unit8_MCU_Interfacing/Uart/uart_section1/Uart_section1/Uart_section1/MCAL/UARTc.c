/*
 * UARTc.c
 *
 * Created: 1/11/2024 4:26:58 PM
 *  Author: XPRISTO
 */ 


#include <avr/io.h>
#include "UART.h"
#include "Queue.h"
#include "../HAL//lcd.h"
#include <avr/interrupt.h>

static uint8_t flag_send=1;
static uint8_t *TX_Str;


uint8_t RX_Buffer[50];


void UART_Init(void)
{
	 /*Set Baud Rate*/
	 UBRRL =51;
	 // Set frame
	 //set 8 bit data , NO parity , 1 stop bit
	 UCSRC |= (1<<1) ;
	 
	 //Enable
	 SET_BIT(UCSRB ,TXEN);
	 SET_BIT(UCSRB ,RXEN);
}

void UART_Transmit(uint8_t data)
{
	while(!CHECK_BIT(UCSRA,UDRE));
	UDR =data;
	
}


uint8_t UART_Recieve(void)
{
	
	while(!CHECK_BIT(UCSRA,RXC));
	return UDR;	
}



void UART_SEND_NUM32(uint32_t NUM)
{
	
	UART_Transmit((uint8_t)(NUM));
	UART_Transmit((uint8_t)(NUM)>>8);
	UART_Transmit((uint8_t)(NUM)>>16);
	UART_Transmit((uint8_t)(NUM)>>24);
	
	
	/*uint8_t *P=&NUM;
	UART_Transmit(P[0]);
	UART_Transmit(P[1]);
	UART_Transmit(P[2]);
	UART_Transmit(P[3]);
	*/
}

uint32_t UART_RecieveNUM32(void)
{
	uint32_t NUM =0;
	
	uint8_t NUM1=UART_Recieve();
	uint8_t NUM2=UART_Recieve();
	uint8_t NUM3=UART_Recieve();
	uint8_t NUM4=UART_Recieve();
	
	 NUM=(uint32_t)NUM1 | (uint32_t)(NUM2<<8) | (uint32_t)(NUM3<<16 ) | (uint32_t)(NUM4<<24);
	
	
	/*
	uint8_t *p=&NUM;
	p[0]=UART_Recieve();
	p[1]=UART_Recieve();
	p[2]=UART_Recieve();
	p[3]=UART_Recieve();
	*/
	
	return NUM;
		
}



void UART_SEND_STR(uint8_t *str)
{
	uint8_t i;
	
	for(i=0;i<str[i];i++)
	{
		UART_Transmit(str[i]);
	}
	UART_Transmit('\r');
}

void UART_RECIEVE_STR(uint8_t *buff)
{
	uint8_t i=0;
	
	buff[i]=UART_Recieve();
	
	while(buff[i]!='\r')
	{
		i++;
		buff[i]=UART_Recieve();
	}
	buff[i]='\0';
	
	
	
}



void UART_SEND_NOBLOCK(uint8_t data)
{
	UDR =data;	
}


uint8_t UART_Recieve_NOBLOCK(void)
{
	return UDR;
}

uint8_t UART_Recieve_PERIODIC_CHECK(uint8_t *ch)
{
	if(CHECK_BIT(UCSRA,RXC))
	{
	 *ch=UDR;
	 return 1;
	}
	else
	{
		return 0;
	} 
}

void UART_TX_IRQEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_IRQDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}


void UART_RX_IRQEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_IRQDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}

void UART_SENDString_Asynch(uint8_t *str)
{
	if(flag_send==1)
	{
		UART_TX_IRQEnable();
		UART_SEND_NOBLOCK(str[0]);
		TX_Str=str;
		flag_send=0;
	}
}


ISR(USART_TXC_vect)
{
	static uint8_t i=1; 
	if(TX_Str[i]!=0)
	{
		UART_SEND_NOBLOCK(TX_Str[i]);
		i++;
	}
	else
	{
		i=1;
		flag_send=1;
	}
}


ISR(USART_RXC_vect)
{
	LCD_INIT();
	static uint8_t j=0;
	uint8_t ch;
	UART_RX_IRQEnable();
	ch=UART_Recieve_NOBLOCK();
	UART_SEND_NOBLOCK(ch);
	LCD_WRITE_CHAR(ch);
	
	
	
	
}

void UART_RecieveString_Asynch(uint8_t *str){
	
	
	
}





