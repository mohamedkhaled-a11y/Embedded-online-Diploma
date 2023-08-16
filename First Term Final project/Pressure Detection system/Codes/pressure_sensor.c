/*
 * pressure_sensor.c
 *
 *  Created on: Jul 15, 2023
 *      Author: XPRISTO
 */


#include "Pressure_sensor.h"
#include "driver.h"
#include <stdint.h>
#include <stdio.h>


void Sensor_init()
{
   Delay(100);

}


int getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}
