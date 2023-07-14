/*
 * Fifo.c
 *
 *  Created on: Jun 26, 2023
 *      Author: XPRISTO
 */

#include "Fifo.h"
#include "stdio.h"





Buffer_Status Enqueue(FIFO_Buf_t *FIFOBUF,element_type enqueue_data)
{
	if(FIFOBUF->length == FIFOBUF->count)
		return FIFO_FULL;

	*(FIFOBUF->Head)=enqueue_data;
	FIFOBUF->count++;

	if(FIFOBUF->Head == (FIFOBUF->base)+(FIFOBUF->length)*sizeof(element_type))
		FIFOBUF->Head=FIFOBUF->base;
	FIFOBUF->Head++;
	return FIFO_NO_ERROR;

}
Buffer_Status DEqueue(FIFO_Buf_t *FIFOBUF,element_type *enqueue_data)
{
	//check if fifo exist

	if(!FIFOBUF->Head || !FIFOBUF->base ||!FIFOBUF->tail)
		return FIFO_NULL;
	//Check is empty
	if(FIFOBUF->count==0)
		{
		printf("FIFO IS Empty\n");
		return FIFO_EMPTY;
		}
	*(enqueue_data)=*(FIFOBUF->tail);
	FIFOBUF->count--;
	if(FIFOBUF->tail == (FIFOBUF->base)+(FIFOBUF->length)*sizeof(element_type))
			FIFOBUF->tail=FIFOBUF->base;
	FIFOBUF->tail++;

	return FIFO_NO_ERROR;

}
Buffer_Status FIFO_ISFULL(FIFO_Buf_t *FIFOBUF)

{
	if(!FIFOBUF->Head || !FIFOBUF->base ||!FIFOBUF->tail)
			return FIFO_NULL;

	if (FIFOBUF->count == FIFOBUF->length)
	{
		printf("FIFO IS FULL\n");
		return FIFO_FULL;
	}

}



Buffer_Status FIFO_Init(FIFO_Buf_t *FIFOBUF,element_type *buff,uint32_t length )

{

FIFOBUF->Head=buff;
FIFOBUF->base=buff;
FIFOBUF->tail=buff;
FIFOBUF->length=length;
FIFOBUF->count=0;

if(FIFOBUF->base && FIFOBUF->length ) return FIFO_NO_ERROR;
else
	return FIFO_NULL;


}
void Fifo_print(FIFO_Buf_t *fifo)

{

	element_type *temp;
	int i;
	if (fifo->count==0)
	{
		printf("FIFO IS Empty\n");
		return FIFO_EMPTY;
	}

	temp=fifo->tail;
	printf("=========================FIFO Print===================");
	for(int i=0;i<fifo->count;i++)
	{
		printf("\t %x  \n",*temp);
		temp++;
	}
}
