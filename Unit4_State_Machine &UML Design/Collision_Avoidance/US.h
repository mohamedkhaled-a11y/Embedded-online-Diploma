/*
 * US.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Mohamed Khaled
 */

#ifndef US_H_
#define US_H_


#include "stdio.h"
#include "stdlib.h"
#include "states.h"

 typedef enum US_states {

	 US_BUSY
}US_StateID;

typedef struct USdata{

	 int distance;
	 US_StateID USstate;
}USdata;

void US_init();
STATEdefine(US_BUSY);

void (*US_state)();
int generaterandom(unsigned int l, unsigned int r, unsigned int count);
#endif /* US_H_ */
