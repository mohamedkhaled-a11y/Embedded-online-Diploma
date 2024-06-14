/*
 * CortexMx_Porting.h
 *
 *  Created on: Apr 20, 2024
 *      Author: XPRISTO
 */

#ifndef CORTEXMX_PORTING_H_
#define CORTEXMX_PORTING_H_


#include "core_cm3.h"


extern  int _estack;
extern  int  _eheap ;
#define Main_Stack_Size            3072


#define OS_SET_PSP(add)        __asm volatile("mov r0,%0 \n\t msr PSP,r0" : : "r" (add) )
#define OS_GET_PSP(add)          __asm volatile("mrs r0,PSP \n\t mov %0,r0"   : "=r" (add) )

#define OS_SWITCH_SP_TO_PSP    __asm volatile("MRS r0, CONTROL \n\t mov r1 , #0x02 \n\t orr r0 ,r0 ,r1 \n\t MSR  CONTROL, r0")
#define OS_SWITCH_SP_TO_MSP    __asm volatile("MRS r0, CONTROL \n\t mov r1 , #0x05 \n\t and r0 ,r0 ,r1 \n\t MSR  CONTROL, r0")


#define OS_SWITCH_TO_PRIVELEDGE     __asm("mrs r3,CONTROL \n\t"       \
			                               "lsr r3 , r3 ,#0x1 \n\t"    \
			                                "lsl r3 , r3 ,#0x1 \n\t"    \
			                                 "msr CONTROL , r3");



#define OS_SWITCH_TO_UNPRIVELEDGE   __asm("mrs r3,CONTROL \n\t"     \
		                                  "orr r3 , r3 ,#0x1 \n\t"   \
			                               "msr CONTROL , r3");
void HW_init();
void trigger_OS_PendSV();
void Start_Ticker();

#endif /* CORTEXMX_PORTING_H_ */
