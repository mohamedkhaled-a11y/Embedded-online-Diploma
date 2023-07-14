/*
 * main.c
 *
 *  Created on: May 6, 2023
 *      Author: XPRISTO
 */

#include "lifo.h"
#include "stdlib.h"
unsigned int Buff[5];

void main()
{

	int temp=0,i=0;
LIFO_TYPE UART_BUFF ,I2C_BUFF;

LIFO_init(&UART_BUFF, Buff,5);

unsigned int *Buff2= (unsigned int *) malloc(5* sizeof(unsigned int));

LIFO_init(&I2C_BUFF, Buff2,5);



for (i=0;i<5;i++)
{
	if (LIFO_add_item(&UART_BUFF, i)==LIFO_NO_ERROR)
		printf("UART_LIFO add : %d \n",i);
}

for (i=0;i<5;i++)
{
	if (LIFO_get_item(&UART_BUFF, &temp)==LIFO_NO_ERROR)
		printf("UART_LIFO get : %d \n",temp);
}





}
