/*
 * schedular.c
 *
 *  Created on: Apr 20, 2024
 *      Author: Mohamed_Khaled
 */


#include "schedular.h"
#include "RTOS_FIFO.h"



struct {
	Task_ref *OSTasks[100]            ;
	unsigned int _S_MSP_              ;
	unsigned int _E_MSP_              ;
	unsigned int _PSP_Task_locator    ;
	unsigned char NoOfActive_Tasks     ;

	Task_ref *PCurrent_Task           ;
	Task_ref *PNext_Task              ;

	enum{
		OSsuspend,
		OSRunning
	}OS_mode_ID;

}OS_Control;

FIFO_Buf_t Ready_QUEUE;
Task_ref *Ready_QUEUE_FIFO[100];
Task_ref MYRTOS_idleTask;
typedef enum {
	SVC_ActivateTask,
	SVC_TerminateTask,
	SVC_TaskWaitingTime
}SVC_ID;



unsigned char idealTask_LED ;
MYRTOS_errorID RTOS_Creat_MainStack();
MYRTOS_errorID RTOS_CreatTaskStack(Task_ref *TASK);
void MYRTOS_IdleTask();
void OS_Set_SVC(SVC_ID  SVC_NUM);
void RTOS_Update_Schedular_Table();
void BubbleSort();
void Decide_whatNext();



MYRTOS_errorID RTOS_Define_Task(Task_ref *task,unsigned int taskStackSize,void(*ptr_task)(),unsigned int taskPriority,char TaskName[10])
{
	    MYRTOS_errorID ERR = NO_ERROR;
    	task->task_stack_size = taskStackSize;
    	task->task_priority  =  taskPriority ;
    	strcpy(task->taskName, TaskName);
    	task->p_task_entry =ptr_task;

    	ERR += RTOS_CREAT_TASK(task);


       return ERR ;


}




__attribute ((naked)) void PendSV_Handler()
{

	//====================================
	//Save the Context of the Current Task
	//====================================
	//Get the Current Task "Current PSP from CPU register" as CPU Push XPSR,.....,R0
	OS_GET_PSP(OS_Control.PCurrent_Task->Current_PSP);

	//using this Current_PSP (Pointer) tp store (R4 to R11)
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r4 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r5 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r6 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r7 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r8 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r9 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r10 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP-- ;
	__asm volatile("mov %0,r11 " : "=r" (*(OS_Control.PCurrent_Task->Current_PSP))  );

	//save the current Value of PSP
	//already saved in Current_PSP



	//====================================
	//Restore the Context of the Next Task
	//====================================
	if (OS_Control.PNext_Task != NULL){
	OS_Control.PCurrent_Task = OS_Control.PNext_Task ;
	OS_Control.PNext_Task = NULL ;
	}

	__asm volatile("mov r11,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;
	__asm volatile("mov r10,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;
	__asm volatile("mov r9,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;
	__asm volatile("mov r8,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;
	__asm volatile("mov r7,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;
	__asm volatile("mov r6,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;
	__asm volatile("mov r5,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;
	__asm volatile("mov r4,%0 " : : "r" (*(OS_Control.PCurrent_Task->Current_PSP))  );
	OS_Control.PCurrent_Task->Current_PSP++ ;

	//update PSP and exit
	OS_SET_PSP(OS_Control.PCurrent_Task->Current_PSP);


	// Check if lr_value is a valid return address
	__asm volatile("BX LR");

}
void OS_SVC(int* Stack_Frame)
{
	//r0,r1,r2,r3,r12,LR,return address (PC) and XPSR
	unsigned char SVC_number ;
	SVC_number = *((unsigned char*)(((unsigned char*)Stack_Frame[6])-2)) ;

	switch(SVC_number)
	{

	case SVC_ActivateTask:
	case SVC_TerminateTask:

		/*update schedular table*/
		/*update Ready Queue*/
		/*OS is Running*/
		/**Decide what Next*/
		/*Trigger PEND_SV*/

		RTOS_Update_Schedular_Table();

		if(OS_Control.OS_mode_ID==OSRunning)
		{
			if(strcmp(OS_Control.PCurrent_Task->taskName,"idleTask")!=0)
			{
				Decide_whatNext();

				trigger_OS_PendSV();

			}
		}

		break;

	case SVC_TaskWaitingTime:
		RTOS_Update_Schedular_Table();

		break;
	}

}
void Decide_whatNext()
{
	//if Ready Queue is empty && OS_Control->currentTask != suspend
	if (Ready_QUEUE.counter == 0 && OS_Control.PCurrent_Task->task_state != Suspended) //FIFO_EMPTY
	{
		OS_Control.PCurrent_Task->task_state  = Running ;
		//add the current task again(round robin)
		FIFO_enqueue(&Ready_QUEUE, OS_Control.PCurrent_Task);
		OS_Control.PNext_Task = OS_Control.PCurrent_Task ;
	}else
	{
		FIFO_dequeue(&Ready_QUEUE, &OS_Control.PNext_Task);
		OS_Control.PNext_Task->task_state = Running ;
		//update Ready queue (to keep round robin Algo. happen)
		if ((OS_Control.PCurrent_Task->task_priority == OS_Control.PNext_Task->task_priority )&&(OS_Control.PCurrent_Task->task_state != Suspended))
		{
			FIFO_enqueue(&Ready_QUEUE, OS_Control.PCurrent_Task);
			OS_Control.PCurrent_Task->task_state = Ready ;
		}
	}
}



MYRTOS_errorID RTOS_Creat_MainStack()
{
	MYRTOS_errorID MainStackErr = NO_ERROR;

	OS_Control._S_MSP_ = &_estack;
	OS_Control._E_MSP_ = OS_Control._S_MSP_ - Main_Stack_Size ;

	OS_Control._PSP_Task_locator = (OS_Control._E_MSP_ - 8);

	if(!OS_Control._S_MSP_ || !OS_Control._E_MSP_ || !OS_Control._PSP_Task_locator)
	{
		MainStackErr += MainStackError;

	}

	return MainStackErr;


}

MYRTOS_errorID RTOS_Init()
{
	HW_init();
	MYRTOS_errorID Init_Err= NO_ERROR;

	/*===================update OS_MODE===============*/
	OS_Control.OS_mode_ID=OSsuspend;

	/*==================Creat Main stack==============*/
	Init_Err+= RTOS_Creat_MainStack();

	/*================Creat QUEUE_Ready===============*/


	if(FIFO_init(&Ready_QUEUE, Ready_QUEUE_FIFO,100)!=FIFO_NO_ERROR)
	{
		Init_Err+=FIFO_READY_QUEUE_ERROR;
	}

	/*=============Configure Ideal_Task=============== */

	strcpy (MYRTOS_idleTask.taskName, "idleTask");
	MYRTOS_idleTask.task_priority = 255 ;
	MYRTOS_idleTask.p_task_entry = MYRTOS_IdleTask ;
	MYRTOS_idleTask.task_stack_size = 512 ;

	Init_Err +=RTOS_CREAT_TASK(&MYRTOS_idleTask);

	return Init_Err;



}


MYRTOS_errorID RTOS_CREAT_TASK(Task_ref *TASK)
{

	MYRTOS_errorID CreatTaskERR = NO_ERROR;
	TASK->_S_PSP_TASK = OS_Control._PSP_Task_locator ;
	TASK->_E_PSP_TASK = TASK->_S_PSP_TASK - TASK->task_stack_size ;

	if(TASK->_E_PSP_TASK < (unsigned int)&_eheap)
	{
		CreatTaskERR = TASK_Exceeds_Stack_size ;
	}

	OS_Control._PSP_Task_locator = (TASK->_E_PSP_TASK - 8 );


	CreatTaskERR+=RTOS_CreatTaskStack(TASK);

	OS_Control.OSTasks[OS_Control.NoOfActive_Tasks]=TASK;
	OS_Control.NoOfActive_Tasks++;

	TASK->task_state=Suspended;


	return CreatTaskERR;

}

MYRTOS_errorID RTOS_CreatTaskStack(Task_ref *TASK)
{
	MYRTOS_errorID StackingErr = NO_ERROR ;

	TASK->Current_PSP = TASK->_S_PSP_TASK  ;
	TASK->Current_PSP -- ;

	*(TASK->Current_PSP) = 0x01000000;   //Dummy xpsr;

	TASK->Current_PSP -- ;
	*(TASK->Current_PSP) = (unsigned int)TASK->p_task_entry;  //PC (return Address)

	TASK->Current_PSP -- ;
	*(TASK->Current_PSP) = 0xFFFFFFFD;         //LR

	for(int i=0;i<13;i++)
	{
		TASK->Current_PSP -- ;
		*(TASK->Current_PSP) = 0;         //LR

	}



	return StackingErr;
}



void RTOS_Activate_Task(Task_ref *TASK)
{

	/*Update Task state*/
	TASK->task_state = Waiting;
	OS_Set_SVC(SVC_ActivateTask);

}

void RTOS_Terminate_Task(Task_ref *TASK)
{
	TASK->task_state = Suspended;
	OS_Set_SVC(SVC_TerminateTask);


}



void OS_Set_SVC(SVC_ID SVC_NUM)
{
	switch(SVC_NUM)
	{
	case SVC_ActivateTask:
		__asm("svc #0x00");
		break;

	case SVC_TerminateTask:
		__asm("svc #0x01");

		break;
	case SVC_TaskWaitingTime:
		__asm("svc #0x02");

		break;


	}

}


void BubbleSort()
{
	unsigned int i , j, n;
	Task_ref *temp;

	n=OS_Control.NoOfActive_Tasks;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(OS_Control.OSTasks[j]->task_priority >  OS_Control.OSTasks[j+1]->task_priority)
			{
				temp=OS_Control.OSTasks[j];
				OS_Control.OSTasks[j]=OS_Control.OSTasks[j+1];
				OS_Control.OSTasks[j+1]=temp;

			}
		}
	}

}

void RTOS_Update_Schedular_Table()
{

	Task_ref *temp;
	unsigned int i=0;

	Task_ref* Pcurrent;
	Task_ref* PNext;

	/*Buble sort the schedulat table based on priority*/
	BubbleSort();

	/*Free Ready Queue*/
	while(FIFO_dequeue(&Ready_QUEUE, &temp)!=FIFO_EMPTY);

	/*Update Ready QUEUE*/

	while(i<OS_Control.NoOfActive_Tasks)
	{
		Pcurrent= OS_Control.OSTasks[i];
		PNext = OS_Control.OSTasks[i+1];

		if(Pcurrent->task_state !=Suspended)
		{
			/*check if we reach the end of schedular table*/
			if(PNext->task_state == Suspended)
			{
				FIFO_enqueue(&Ready_QUEUE, Pcurrent);
				Pcurrent->task_state = Ready;
				break;
			}

			else if(Pcurrent->task_priority < PNext->task_priority )
			{
				FIFO_enqueue(&Ready_QUEUE, Pcurrent);
				Pcurrent->task_state = Ready;
				break;
			}

			else if(Pcurrent->task_priority == PNext->task_priority )
			{
				FIFO_enqueue(&Ready_QUEUE, Pcurrent);
				Pcurrent->task_state = Ready;
			}
			else if(Pcurrent->task_priority > PNext->task_priority )
			{
				break;
			}

		}


		i++;
	}


}

void MYRTOS_STARTOS()
{

	OS_Control.OS_mode_ID=OSRunning;

	OS_Control.PCurrent_Task =&MYRTOS_idleTask;
	RTOS_Activate_Task(&MYRTOS_idleTask);

	Start_Ticker();

	OS_SET_PSP(OS_Control.PCurrent_Task->Current_PSP);


	OS_SWITCH_SP_TO_PSP ;
	OS_SWITCH_TO_UNPRIVELEDGE ;

	MYRTOS_idleTask.p_task_entry();





}



void MYRTOS_IdleTask()
{
	while(1)
	{
		idealTask_LED ^=1;
		__asm("wfe") ;
	}

}




void RTOS_TASK_Wait(Task_ref *TASK,unsigned int Ticks)
{

    TASK->Timingwaiting.Blocking=Timing_Block_Enable;
    TASK->Timingwaiting.Tick_Counts=Ticks;

    TASK->task_state=Suspended;
    OS_Set_SVC(SVC_TerminateTask);


}

void RTOS_update_Task_Timing()
{
	for(int i=0;i<OS_Control.NoOfActive_Tasks;i++)
	{
		if(OS_Control.OSTasks[i]->task_state==Suspended)
		{
			if(OS_Control.OSTasks[i]->Timingwaiting.Blocking==Timing_Block_Enable)
			{
				OS_Control.OSTasks[i]->Timingwaiting.Tick_Counts--;

				if(OS_Control.OSTasks[i]->Timingwaiting.Tick_Counts==0)
				{
					OS_Control.OSTasks[i]->Timingwaiting.Blocking=Timing_Block_Disable  ;
					OS_Control.OSTasks[i]->task_state=Waiting;
					OS_Set_SVC(SVC_TaskWaitingTime);
				}


			}

		}
	}
}


MYRTOS_errorID RTOS_Creat_Mutex(Mutex_ref *mMutex,unsigned char *payload , unsigned int payloadSize,char MutexName[10])
{

mMutex->payloadSize=payloadSize;
mMutex->Payload=payload;
strcpy(mMutex->MutxName,MutexName );

return NO_ERROR;

}

MYRTOS_errorID Aquire_Mutex(Mutex_ref * mMutex, Task_ref *task)
{

   if(mMutex->Currenttask == NULL)
   {
	   mMutex->Currenttask = task;
   }
   else
   {
	   if(mMutex->Nexttask ==NULL)
	   {
		   mMutex->Nexttask = task;
		   task->task_state=Suspended;
		   OS_Set_SVC(SVC_TerminateTask);


	   }
	   else
	   {
		   return Mutex_Exceeds_Max_No_Of_Users ;
	   }


   }


   return NO_ERROR;

}

void Release_Mutex(Mutex_ref * mMutex)
{

	if (mMutex->Currenttask !=NULL)
	{
		mMutex->Currenttask = mMutex->Nexttask ;
		mMutex->Nexttask=NULL;
		mMutex->Currenttask->task_state = Waiting;
		OS_Set_SVC(SVC_ActivateTask);

	}


}







