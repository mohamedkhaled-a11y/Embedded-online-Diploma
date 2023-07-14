/*
 * CollisionAvoidance.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Mohamed khaled
 */

#ifndef COLLISIONAVOIDANCE_H_
#define COLLISIONAVOIDANCE_H_


#include "stdio.h"
#include "stdlib.h"

 typedef enum states {

	waiting,
	Driving
}StateID;


void (*CA_state)();
typedef struct cars{

	 int distance;
	 int speed;
	 int threshold;
	 StateID carstate;
}cars;


#define STATEdefine(_stateFunc_)  void ST_##_stateFunc_()

#define STATE(_stateFunc_)  ST_##_stateFunc_

STATEdefine(waiting);
STATEdefine(Driving);




#endif /* COLLISIONAVOIDANCE_H_ */
