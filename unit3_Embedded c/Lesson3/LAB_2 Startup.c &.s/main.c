


//Mohamed_Khaled_Ahmed

typedef volatile unsigned int vuint32_t;
#include<stdint.h>

#define GPIOP_Base     0x40010800
#define RCC_BASE       0X40021000

#define APB2ENR             *(vuint32_t *)(RCC_BASE+0X18)
#define GPIOPA_CRH         *(vuint32_t *)(GPIOP_Base+0X04)
#define GPIOPA_ODR         *(vuint32_t *)(GPIOP_Base+0x0c)


//bitfields

#define RCC_IOPAEN (1<<2)
#define GPIOA13 (1UL<<13)

typedef union {

       vuint32_t allfields;
       struct 
       {
       	  vuint32_t   resrved:13;
       	  vuint32_t   P13:1;

       }pin;


}R_ODR_t;



extern void NMI_Handler(void)
{
}
extern void Bus_Fault(void)
{
}


//define R_ODR_t variable

volatile R_ODR_t *R_ODR_= (volatile R_ODR_t *)(GPIOP_Base+0x0c);

int main(void)
{
   APB2ENR |= RCC_IOPAEN;
   GPIOPA_CRH &= 0xFF0FFFFF;
   GPIOPA_CRH  |= 0x00200000;
   
   while(1)
   {
        R_ODR_->pin.P13=1;

        for (int i=0;i<5000;i++);

		R_ODR_->pin.P13=0;

		for (int i=0;i<5000;i++);

}

	return 0;
}