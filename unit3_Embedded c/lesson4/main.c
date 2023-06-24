

typedef volatile unsigned int vuint_32_t;
#include<stdint.h>


#define SYSCTRL_Base              0x400FE000
#define GPIO_PORTF_Base           0x40025000




#define SYSCTRL_RCGC2_R_          *(vuint_32_t *)(SYSCTRL_Base+0X108)
#define GPIO_PORTF_DIR_R          *(vuint_32_t *)(GPIO_PORTF_Base+0x400)
#define GPIO_PORTF_DEN_R          *(vuint_32_t *)(GPIO_PORTF_Base+0X51C)
#define GPIO_PORTF_DATA_R         *(vuint_32_t *)(GPIO_PORTF_Base+0x3FC)

int main(void)
{


SYSCTRL_RCGC2_R_ =0x020;

//at using any clk we should make a delay to 

vuint_32_t delay_count;


for(delay_count=0;delay_count<200;delay_count++);
GPIO_PORTF_DIR_R|=(1<<3);
GPIO_PORTF_DEN_R|=(1<<3);


while(1)
{
	GPIO_PORTF_DATA_R |=(1<<3);
	for(delay_count=0;delay_count<200000;delay_count++);
	GPIO_PORTF_DATA_R &=~(1<<3);
	for(delay_count=0;delay_count<200000;delay_count++);

}


	return 0;

}