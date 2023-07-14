/*
 * DC.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Mohamed khaled
 */

#ifndef DC_H_
#define DC_H_


#include "stdio.h"
#include "stdlib.h"

 typedef enum DC_states {

	DC_idle,
	DC_busy
}DC_StateID;


typedef struct DC_motor{

	 int speed;
	 DC_StateID DCstate;
}DC_motor;




/*unsigned int distance;
unsigned int speed;
unsigned int threshold=50;
*/
void (*DC_state)();

void DC_init();


STATEdefine(DC_idle);
STATEdefine(DC_busy);


#endif /* DC_H_ */
