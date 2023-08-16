/*
 * main.c
 *
 *  Created on: Jul 20, 2023
 *      Author: XPRISTO
 */

#include "students.h"
#include "stdio.h"

#define DPRINTF(...)    {   fflush(stdout);   \
		fflush(stdin);     \
		printf(__VA_ARGS__); \
		fflush(stdout);   \
		fflush(stdin);}

QUEUE_t *BUFF;
Student_info stud;
Student_info *std;



void main()
{
	Queue_init(&BUFF);
	char temptext[40];
	//char str[8]= "stud.txt";
	//int n;

	FILE *fp=fopen("stud.txt","r+");

	while(1)
	{
		DPRINTF("\n=========================");
		DPRINTF("\n\t Choose one of the following options \n");
		DPRINTF("\n 1: Add student manualy  ");
		DPRINTF("\n 2: Add file of students  ");
		DPRINTF("\n 3: View students  ");
		DPRINTF("\n 4: Find a course  ");
		DPRINTF("\n 5: Find student info with name  ");
		DPRINTF("\n 6: Find student info with ID  ");
		DPRINTF("\n 7: update student info  ");
		DPRINTF("\n 8: Delete student ");
		DPRINTF("\n 9: Total students ");


		gets(temptext);

		switch(atoi(temptext)){
		DPRINTF("\n=========================");
		case 1:
			add_student_manualy(&BUFF,stud);
			break;
		case 2:
			add_student_file(&BUFF,stud,fp);
			break;
		case 3:
			show_students(&BUFF);
			break;
		case 4:
			find_course(&BUFF);
			break;
		case 5:
			find_fname(&BUFF);
			break;
		case 6 :
			find_ID(&BUFF);
			break;
		case 7:
			update_stud_info(&BUFF);
			break;
		case 8:
			delete_student(&BUFF,&std);
			break;
		case 9:
			total_stud(&BUFF);
			break;
		default:
			DPRINTF("wrong choice");
		}

	}
}



