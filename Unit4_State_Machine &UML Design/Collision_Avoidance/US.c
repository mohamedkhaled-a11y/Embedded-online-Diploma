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
extern void (*US_state)();



USdata USsensor;

int generaterandom(unsigned int l, unsigned int r, unsigned int count)
{
     int i;
     for(i=0;i<count;i++)
     {
    	 int rand_num= (rand() % (r-l+1))+l;
    	 return rand_num;
     }

}

 void (*state)();

STATEdefine(US_BUSY)
{

	US_distance (USsensor.distance=generaterandom(45,55,1));
	US_state=STATE(US_BUSY);
}




