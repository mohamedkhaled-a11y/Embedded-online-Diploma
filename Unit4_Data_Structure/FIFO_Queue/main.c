/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: XPRISTO
 */


#include "Fifo.h"

#define Buffer1_len  5

element_type buffer1[Buffer1_len];

void main ()
{

FIFO_Buf_t Uart_Fifo;
unsigned char i,temp=0;

if(FIFO_Init(&Uart_Fifo, buffer1, Buffer1_len)==FIFO_NO_ERROR)
		printf("FIFO Init--------DONE\n");

for (i=0;i<7;i++)
{

	printf("FIFO Enqueue (%x) \n",i);
	if(Enqueue(&Uart_Fifo, i)==FIFO_NO_ERROR)
		printf("FIFO ENqueue (%x) ------DONE\n",i);
	else
		printf("FIFO ENqueue (%x)-------Failed \n",i);

}

}
