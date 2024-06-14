/*
 * schedular.h
 *
 *  Created on: Apr 20, 2024
 *      Author: XPRISTO
 */

#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_


#include "CortexMx_Porting.h"


typedef enum{

	NO_ERROR,
	FIFO_READY_QUEUE_ERROR,
	TASK_Exceeds_Stack_size,
	MainStackError,
	StackingError,
	TASK_Activation_ERROR,
	TASK_Termenation_ERROR,
	Mutex_Exceeds_Max_No_Of_Users


}MYRTOS_errorID;

typedef struct
{
	unsigned int  task_stack_size    ;
	unsigned int  task_priority      ;
	void (*p_task_entry)(void)       ;
	unsigned char Autostart          ;
	unsigned int _S_PSP_TASK         ;
	unsigned int _E_PSP_TASK         ;
	unsigned int *Current_PSP        ;
	unsigned char taskName[30]       ;

	enum{
		Suspended,
		Waiting  ,
		Ready    ,
		Running  ,
	}task_state;

	struct {

		enum{
			Timing_Block_Enable,
			Timing_Block_Disable
		}Blocking;

		unsigned int Tick_Counts;
	}Timingwaiting;

}Task_ref;


typedef struct {

	unsigned char         *Payload;
	unsigned int          payloadSize;
	Task_ref              *Currenttask;
	Task_ref              *Nexttask;
	unsigned char          MutxName[30] ;

}Mutex_ref;


//APIs

MYRTOS_errorID RTOS_Init();
MYRTOS_errorID RTOS_CREAT_TASK(Task_ref *TASK);
void MYRTOS_STARTOS();

void RTOS_Activate_Task(Task_ref *TASK);
void RTOS_Terminate_Task(Task_ref *TASK);
void RTOS_TASK_Wait(Task_ref *TASK,unsigned int Ticks);

MYRTOS_errorID RTOS_Creat_Mutex(Mutex_ref *mMutex,unsigned char *payload , unsigned int payloadSize,char MutexName[10]);

MYRTOS_errorID Aquire_Mutex(Mutex_ref * mMutex, Task_ref *task);
void Release_Mutex(Mutex_ref * mMutex);

MYRTOS_errorID RTOS_Define_Task(Task_ref *task,unsigned int taskStackSize,void(*ptr_task)(),unsigned int taskPriority,char TaskName[10]);



#endif /* SCHEDULAR_H_ */
