/*
 * CollisionAvoidance.c
 *
 *  Created on: Jul 7, 2023
 *      Author: Mohamed Khaled
 */


#include "CollisionAvoidance.h"
#include "DC.h"
#include "states.h"

extern  void (*DC_state)();

DC_motor motor;

 void (*DC_state)();

 DC_Speed_set(int s){

     motor.speed=s;
	 (motor.speed ==0 )? (DC_state=STATE(DC_busy)): (DC_state=STATE(DC_idle));
 }



STATEdefine(DC_idle)
{

	motor.DCstate=DC_idle;
	motor.speed=30;
	printf(" Motor is in idle state :  speed = %d \n",motor.speed);
	DC_state=STATE(DC_idle);

}

STATEdefine(DC_busy)
{


	motor.DCstate=DC_busy;
	motor.speed=0;
	printf("Motor is in busy state :  speed = %d \n",motor.speed);
	DC_state=STATE(DC_busy);
}




