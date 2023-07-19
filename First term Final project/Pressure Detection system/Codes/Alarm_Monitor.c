/*
 * Alarm_Monitor.c
 *
 *  Created on: Jul 15, 2023
 *      Author: XPRISTO
 */


#include "Alarm_Monitor.h"
#include "driver.h"
#include "Alarm_led.h"

void High_Presuure_Detect()
{
 Set_Alarm_actuator(1);
 Delay(100);
}


void Normal_Pressure()
{

	 Set_Alarm_actuator(0);
	 Delay(100);
}

