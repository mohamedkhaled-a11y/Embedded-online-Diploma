


/*Linker_Script.ld_Cortex M3
ENG:Mohamed Khaled
*/



MEMORY
{
	flash(RX)  : ORIGIN = 0X0000000, LENGTH = 512M
	sram(RWX)  : ORIGIN = 0X2000000, LENGTH = 512M
}


SECTIONS 
{
	.text : {

	        *(.vectors*)
	        *(.text*)
	        *(.rodata*)
	        _E_Text = . ;
	}>flash

	.data : {
	        _S_DATA = . ;
	        *(.data*)
	        _E_DATA = . ;
	}>sram AT> flash

	.bss : {
	       _S_bss = . ;

	       *(.bss*)
	       . = ALIGN(4);
            _E_bss = . ;

	}>sram
}