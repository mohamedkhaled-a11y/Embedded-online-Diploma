/*
 * Algorithm.c
 *
 *  Created on: Jul 15, 2023
 *      Author: XPRISTO
 */



#include "Pressure_sensor.h"
#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "Algorithm.h"
#include "Alarm_Monitor.h"

#define Pthreshold  20


void Pressure_Detection()
{
	int x=getPressureVal();

	if(x>Pthreshold)
		High_Presuure_Detect();
	else
		Normal_Pressure();

}
