

ENTRY (reset)



MEMORY 
{

 MEM (rwx)    : ORIGIN = 0x00000000, LENGTH = 0x4000000
	
 }

SECTIONS 
{
	
	. = 0x10000;
	.startup . :
	{
       startup.o(.text)

	}>MEM

	.text :
	{

        *(.text) *(.rodata)

	}>MEM

	.data :
	{
     *(.data)
	}>MEM

	.bss :
	{

     *(.bss)  *(COMMON)

	}>MEM

	. = . + 0x10000 ;       /*4KB OF STACK*/

	stack_top = . ;
}