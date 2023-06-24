//Startup.c
//ENG:Mohamed_Khaled



#include <stdint.h>
extern int main(void);

void Rest_Handler (void) ;
void Default_Handler()
{
Rest_Handler() ;
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void MM_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_Fault(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));;

extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
//extern unsigned int _stack_top ;

//make an unintitialized global array with size of 1024 Bytes(256 elements) to be saved in .bss section

static uint32_t Stack_top[256];   //static to limit the variable scope

void (* const G_P_vectors[])() __attribute__((section(".vectors"))) =
{

  (void (*)())  ((uint32_t )Stack_top +sizeof(Stack_top)),
   &Rest_Handler,
   &NMI_Handler ,
   &H_fault_Handler ,
   &MM_Fault_Handler ,
   &Bus_Fault ,
   &Usage_Fault_Handler
};

/*uint32_t vectors[] __attribute__((section(".vectors"))) = {
(uint32_t) &_stack_top,
(uint32_t) &Rest_Handler,
(uint32_t) &NMI_Handler ,
(uint32_t) &H_fault_Handler ,
(uint32_t) &MM_Fault_Handler ,
(uint32_t) &Bus_Fault ,
(uint32_t) &Usage_Fault_Handler
};

*/
void Rest_Handler (void)
{


  unsigned int DATA_SIZE= (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
  unsigned char *P_SRC=(unsigned char *)&_E_DATA;
  unsigned char *P_dst=(unsigned char *)&_S_DATA;

  for(int i=0;i<DATA_SIZE;i++)
  {

     *((unsigned char*)P_dst++)=*((unsigned char*)P_SRC++);


  } 


unsigned int bss_size=(unsigned char *)&_E_bss - (unsigned  char *)&_S_bss ;
P_dst=(unsigned char *)&_S_bss;

for(int i=0;i<bss_size;i++)
  {

     *((unsigned char*)P_dst++)=(unsigned char)0;

  } 

main();
}






