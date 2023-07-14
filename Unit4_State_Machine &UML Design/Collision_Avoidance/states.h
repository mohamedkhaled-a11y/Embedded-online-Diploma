/*
 * states.h
 *
 *  Created on: Jul 9, 2023
 *      Author: Mohamed khaled
 */

#ifndef STATES_H_
#define STATES_H_

#include "stdio.h"
#include "stdlib.h"

#define STATEdefine(_stateFunc_)  void ST_##_stateFunc_()
#define STATE(_stateFunc_)  ST_##_stateFunc_


US_distance (int d);

DC_Speed_set(int s);









#endif /* STATES_H_ */
