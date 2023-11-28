/*
 * GccApplication1.c
 *
 * Created: 8/27/2023 10:14:40 PM
 * Author : XPRISTO
 */ 
#define F_CPU 8000000ul
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/*
#define  IO_BASE 0x20
#define  SREG   (IO_BASE +0x3F)
*/


void INT_Init();
void GPIO_Init();
int main(void)
{
	INT_Init();
	GPIO_Init();
    
    while (1) 
    {
    }
	
}
void GPIO_Init()
{
	//configure PORTD (PIN 2,3) AS input
	DDRD &= ~(0b11<<2);
	//configure PORTD_as output
	DDRD |= (1<<7 | 1<<6 | 1<<5);
	
	//TURN LEDs off
	
	DDRD &= ~(1<<7 | 1<<6 | 1<<5);

	
}


void INT_Init()
{
	
	
	//Making INT0 Trigger on any logical change
	
	MCUCR |= (1<<0);
	MCUCR &= ~(1<<1);
	
	//Making INT1 trigger on Rising edge

/*	
	MCUCR |= (1<<2);
	MCUCR |= (1<<3);
	
*/
   
   MCUCR |= (1<<ISC11);


	//Making INT2 trigger on falling edge
	MCUCSR &= ~(1<<6);
	
	
	//Enabling external interrupt
	GICR |= (1<<7 | 1<<6 | 1<<5);
	
	SREG |= (1<<7);
	
	
	
}












ISR(INT0_vect)
{
	PORTD |= (1<<5);
	_delay_ms(1000);
	
	PORTD &= ~(1<<5);
	
	
}

ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(1000);
	
	PORTD &= ~(1<<6);
	
}
ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
	PORTD &= ~(1<<7);
}

