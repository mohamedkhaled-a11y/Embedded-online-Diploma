/*
 * lifo.h
 *
 *  Created on: May 6, 2023
 *      Author: XPRISTO
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"

typedef struct {

	unsigned int* Base;
	unsigned int* Head;
	unsigned int length;
	unsigned int count;
}LIFO_TYPE;

typedef enum {

	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFIO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL

}LIFO_Status;

LIFO_Status LIFO_init(LIFO_TYPE *lbuf,unsigned int *Buff,unsigned int length);
LIFO_Status LIFO_add_item(LIFO_TYPE *lbuf,unsigned int item);
LIFO_Status LIFO_get_item(LIFO_TYPE *lbuf,unsigned int *item);



#endif /* LIFO_H_ */
