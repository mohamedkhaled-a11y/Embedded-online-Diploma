/*
 * Fifo.h
 *
 *  Created on: Jun 26, 2023
 *      Author: XPRISTO
 */

#ifndef FIFO_H_
#define FIFO_H_


#include "stdio.h"
#include <stdint.h>





//configure the element type (uint8_t , uint32_t, uint16_t)

typedef unsigned char uint8_t ;
typedef unsigned int uint32_t ;


#define element_type uint8_t

typedef struct {

	unsigned int length;
	unsigned char *base;
	unsigned char *Head;
	unsigned char *tail;
	unsigned int count;
}FIFO_Buf_t;



typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,
}Buffer_Status;


Buffer_Status Enqueue(FIFO_Buf_t *FIFOBUF,element_type enqueue_data);
Buffer_Status DEqueue(FIFO_Buf_t *FIFOBUF,element_type *enqueue_data);
Buffer_Status FIFO_ISFULL(FIFO_Buf_t *FIFOBUF);
Buffer_Status FIFO_Init(FIFO_Buf_t *FIFOBUF,element_type *buff,uint32_t length );
void Fifo_print(FIFO_Buf_t *fifo);










#endif /* FIFO_H_ */
