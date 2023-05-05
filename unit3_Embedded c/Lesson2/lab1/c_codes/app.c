#include"uart.h"

unsigned char str_buffer[100]= "Learn-in-depth:Mohamed";
void main(void)
{
uart_send_string(str_buffer);

}