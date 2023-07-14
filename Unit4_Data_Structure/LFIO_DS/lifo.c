/*
 * lifo.c
 *
 *  Created on: May 6, 2023
 *      Author: XPRISTO
 */

#include "lifo.h"
LIFO_Status LIFO_add_item(LIFO_TYPE * lbuf,unsigned int item)
{
	//CHAECKING IF lifo is not exist
	if (!lbuf->Base || !lbuf->Head)
		return LIFO_NULL;

	//checking if lifo is full
	if(lbuf->count==lbuf->length)
		return LIFO_FULL;
	*(lbuf->Head)=item;
	lbuf->Head++;
	lbuf->count++;

	return LIFO_NO_ERROR;


}

LIFO_Status LIFO_get_item(LIFO_TYPE *lbuf,unsigned int *item)
{

	//CHAECKING IF lifo is not exist
	if (!lbuf->Base || !lbuf->Head)
		return LIFO_NULL;

	//checking if lifo is EMpty
	if(lbuf->count==0)
		return LIFIO_EMPTY;
	lbuf->Head--;
	*item=*(lbuf->Head);
	lbuf->count--;


	return LIFO_NO_ERROR;


}

LIFO_Status LIFO_init(LIFO_TYPE *lbuf,unsigned int* Buff,unsigned int length)
{

	if (Buff==NULL)
		return LIFO_NULL;

	lbuf->Base=Buff;
	lbuf->Head=Buff;
	lbuf->length=length;
	lbuf->count=0;

	return LIFO_NO_ERROR;
}



