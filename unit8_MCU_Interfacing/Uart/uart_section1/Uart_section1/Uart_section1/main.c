/*
 * Uart_section1.c
 *
 * Created: 1/11/2024 2:36:01 PM
 * Author : XPRISTO
 */ 


#include "HAL//lcd.h"
#include "HAL//keypad.h"
#include "MCAL/UART.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void main(void)
{
	
	
	LCD_INIT();
	UART_Init();
	
	LCD_GOTO_XY(0,0);
	uint8_t l[10]="UART TR";
	LCD_WRITE_STRING(l);
	 

    uint8_t Buff[50];
	uint8_t ch[50]="Mohamed";
	UART_SEND_STR(ch);
	





      while (1) 
    {
		
		
		UART_RECIEVE_STR(&Buff);
		LCD_WRITE_STRING(&Buff);
		UART_SEND_STR(&Buff);

		
    }
}

