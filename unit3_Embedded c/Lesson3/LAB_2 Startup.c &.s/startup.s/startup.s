/*Startup cortex_M3.S
ENG:MohamedKhaled*/


/*SRAM=0X20000000*/

/*Vectors*/

.section .vectors

.word        0X20001000                /*Stack_top address*/
.word        _reset                   /* first_reset*/
.word        Vector_handler          /* NMI*/
.word        Vector_handler         /* hard fault*/
.word        Vector_handler        /*MM fault*/
.word        Vector_handler        /*BUS fault*/
.word        Vector_handler        /*Usage fault*/
.word        Vector_handler        /*Reserved*/
.word        Vector_handler        /*Reserved*/
.word        Vector_handler        /*Reserved*/
.word        Vector_handler        /*Reserved*/
.word        Vector_handler        /*sv_call*/
.word        Vector_handler        /*debug reserved*/
.word        Vector_handler
.word        Vector_handler
.word        Vector_handler
.word        Vector_handler
.word        Vector_handler
.word        Vector_handler
.word        Vector_handler


.section .text
_reset:
     bl main
     b .

.thumb_func
.vector_handler:
     b _reset