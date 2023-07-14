/*
 * main.c
 *
 *  Created on: Jul 9, 2023
 *      Author: Mohamed Khaled
 */


#include "CollisionAvoidance.h"
#include "US.h"
#include "states.h"
#include "stdio.h"
#include "stdlib.h"
#include "DC.h"

void setup()
{

US_state=STATE(US_BUSY);
CA_state=STATE(waiting);
DC_state=STATE(DC_idle);


}


void main()
{

setup();

volatile int d;


while(1)
{
	US_state();
	CA_state();
	DC_state();

 for(d=0;d<1000;d++);

}


}
