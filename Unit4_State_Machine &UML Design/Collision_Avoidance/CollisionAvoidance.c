/*
 * CollisionAvoidance.c
 *
 *  Created on: Jul 7, 2023
 *      Author: Mohamed khaled
 */


#include "CollisionAvoidance.h"
#include "US.h"
#include "states.h"
#include "stdio.h"
#include "stdlib.h"


cars car;
extern  void (*CA_state)();


 US_distance (int d)
 {
	 car.threshold=50;
	 car.distance=d;
	 (car.distance <= car.threshold)? (CA_state=STATE(waiting)): (CA_state=STATE(Driving));
 }
STATEdefine(waiting)
{
	car.carstate=waiting;
	car.speed=0;
	DC_Speed_set(car.speed);
	printf("\n waiting state : distance = %d speed = %d \n",car.distance,car.speed);
}

STATEdefine(Driving)
{

	car.carstate=Driving;
	car.speed=30;
	DC_Speed_set(car.speed);
	printf("\n driving state : distance = %d speed = %d \n",car.distance,car.speed);
}



