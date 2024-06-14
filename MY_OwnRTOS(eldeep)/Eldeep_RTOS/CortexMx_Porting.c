/*
 * CortexMx_Porting.c
 *
 *  Created on: Apr 20, 2024
 *      Author: XPRISTO
 */

#include "CortexMx_Porting.h"


unsigned char SYSTIK_LED;

  void NMI_Handler(void)
  {

	  while(1);

  }
  void HardFault_Handler(void)
  {

	  while(1);

  }
  void	MemManage_Handler(void)
  {
/*
	  __asm volatile (
	          "TST lr, #4 \n"
	          "ITE EQ \n"
	          "MRSEQ r0, MSP \n"
	          "MRSNE r0, PSP \n"
	          "B hard_fault_handler_c \n"
	      );

*/
	  while(1);

  }
  void	BusFault_Handler(void)
  {

	  while(1);
  }
  void	UsageFault_Handler(void)
  {

	  while(1);
  }






  __attribute ((naked)) void SVC_Handler ()
  {
  	//	SWITCH_CPU_AccessLevel (privileged);
  	__asm ("tst lr, #4 \n\t"
  			"ITE EQ \n\t" //To execute Thumb instructions conditionally, you can either use an IT instruction, or a conditional branch instruction.
  			"mrseq r0,MSP \n\t "
  			"mrsne r0,PSP \n\t"
  			"B OS_SVC");
  }




  void HW_init()
  {
  	//Initialize Clock Tree (RCC -> SysTick Timer & CPU) 8MHZ
  	//init HW
  	//Clock tree
  	//RCC Default Values makes CPU Clock & SySTick Timer clock = 8 M HZ

  	//	8 MHZ
  	//	1 count -> 0.125 us
  	//	X count -> 1 ms
  	//	X = 8000 Count



  	//	decrease PenSV  interrupt priority to be  smaller than or equal  SySTICK Timer
  	//SysTICK have a priority 14
  	__NVIC_SetPriority(PendSV_IRQn, 15) ;
  	// Enable usage fault, bus fault, and memory management fault
  	SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk | SCB_SHCSR_MEMFAULTENA_Msk;


  }



  void trigger_OS_PendSV()
  {
  	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk ;

  }



 void Start_Ticker()
 {
		//	This clock tree should be defined in HW_init()
		//	8 MHZ
		//	1 count -> 0.125 us
		//	X count -> 1 ms
		//	X = 8000 Count

		 SysTick_Config(8000);

 }

 void SysTick_Handler(void)
 {
	 SYSTIK_LED ^=1;
	 RTOS_update_Task_Timing() ;

	 Decide_whatNext();

	 trigger_OS_PendSV();


 }


/*

 void hard_fault_handler_c(uint32_t *hardfault_args) {
     uint32_t stacked_r0  = hardfault_args[0];
     uint32_t stacked_r1  = hardfault_args[1];
     uint32_t stacked_r2  = hardfault_args[2];
     uint32_t stacked_r3  = hardfault_args[3];
     uint32_t stacked_r12 = hardfault_args[4];
     uint32_t stacked_lr  = hardfault_args[5];
     uint32_t stacked_pc  = hardfault_args[6];
     uint32_t stacked_psr = hardfault_args[7];

     // Analyze the values of these registers to understand the cause
     while(1);
 }

*/
