/*
 * Alarm_led.c
 *
 *  Created on: Jul 15, 2023
 *      Author: XPRISTO
 */



#include "Alarm_led.h"
#include "driver.h"

void Set_Alarm_actuator(int i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}


