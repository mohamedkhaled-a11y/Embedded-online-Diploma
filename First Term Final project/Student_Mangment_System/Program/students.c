/*
 * students.c
 *
 *  Created on: Jul 20, 2023
 *      Author: XPRISTO
 */


#include "students.h"
#include "string.h"
#include "stdio.h"

#define DPRINTF(...)    {   fflush(stdout);   \
		fflush(stdin);     \
		printf(__VA_ARGS__); \
		fflush(stdout);   \
		fflush(stdin);}



int MAX_QUEUE =55;
QUEUE_Status Queue_init(QUEUE_t *BUFF)
{

	BUFF->front=0;
	BUFF->rear=-1;
	BUFF->length=0;

	return QUEUE_NO_ERROR;

}

QUEUE_Status add_student_manualy(QUEUE_t *BUFF,Student_info stud)
{
	add_info(&stud);
	BUFF->rear=(BUFF->rear+1) %MAX_QUEUE;
	BUFF->Student_QUEUE[BUFF->rear]=stud;
	BUFF->length++;


	return QUEUE_NO_ERROR;
}



void add_info(Student_info *stud)
{
	char inp[50];
	DPRINTF("Enter First Name : ");
	gets(stud->fname);
	DPRINTF("\n Enter Last Name : ");
	gets(stud->lname);
	DPRINTF("\n Enter student ID : ");
	stud->ID=atoi(gets(inp));
	DPRINTF("\n Enter GPA : ");
	stud->GPA=atof(gets(inp));

	for(int i=0;i<5;i++)
	{
		DPRINTF("\n Enter Course %d: ID : ",i+1);
		scanf("%d",&stud->CourseID[i]);
	}

}



void find_ID(QUEUE_t *PQ)
{
	int id;
	DPRINTF("Enter student ID :");
	scanf("%d",&id);

	int pos,s;
	for(pos=PQ->front,s=0;s<PQ->length;s++)
	{

		if (PQ->Student_QUEUE[pos].ID==id)
		{
			DPRINTF("FOUND \n");
			break;
		}
		pos=(pos+1)%MAX_QUEUE;
	}

	DPRINTF("Student Number %d",s+1);
	DPRINTF("\n Student First Name %s ",PQ->Student_QUEUE[pos].fname);
	DPRINTF("\n Student Last Name %s ",PQ->Student_QUEUE[pos].lname);
	DPRINTF("\n Student ID %d ",PQ->Student_QUEUE[pos].ID);
	DPRINTF("\n Student GPA %f ",PQ->Student_QUEUE[pos].GPA);
	for(int i=0;i<5;i++){
		DPRINTF("\n Student Course %d ID:  %d ",i+1,PQ->Student_QUEUE[pos].CourseID[i]);
	}
}




void find_fname(QUEUE_t *PQn){
	char name[50];
	DPRINTF("Enter First Name : ");
	gets(name);

	int pos,s;
	for(pos=PQn->front,s=0;s<PQn->length;s++)
	{

		if (strcmp(PQn->Student_QUEUE[pos].fname,name)==0)
		{
			DPRINTF("FOUND \n");
			break;
		}
		pos=(pos+1)%MAX_QUEUE;
	}

	DPRINTF("Student Number %d",s+1);
	DPRINTF("\n Student First Name %s ",PQn->Student_QUEUE[pos].fname);
	DPRINTF("\n Student Last Name %s ",PQn->Student_QUEUE[pos].lname);
	DPRINTF("\n Student ID %d ",PQn->Student_QUEUE[pos].ID);
	DPRINTF("\n Student GPA %f ",PQn->Student_QUEUE[pos].GPA);

	for(int i=0;i<5;i++){
		DPRINTF("\n Student Course %d ID:  %d ",i+1,PQn->Student_QUEUE[pos].CourseID[i]);
	}

}

void find_course(QUEUE_t *PQn){

	int course;
	DPRINTF("Enter course ID : ");
	scanf("%d",&course);
	int pos,s,count=0;
	for(pos=PQn->front,s=0;s<PQn->length;s++)
	{
		for(int i=0;i<5;i++){

			if (PQn->Student_QUEUE[pos].CourseID[i]==course)
			{
				DPRINTF("YES");
				count+=1;
			}

		}
		pos=(pos+1)%MAX_QUEUE;
	}

	DPRINTF("The course %d has a %d students",course,count);
}



void show_students(QUEUE_t *PQ)
{


	int pos,s;
	for(pos=PQ->front,s=0;s<PQ->length;s++)
	{
		DPRINTF("\n\n Student Number %d",s+1);
		DPRINTF("\n Student First Name: %s ",PQ->Student_QUEUE[pos].fname);
		DPRINTF("\n Student Last Name: %s ",PQ->Student_QUEUE[pos].lname);
		DPRINTF("\n Student ID: %d ",PQ->Student_QUEUE[pos].ID);
		DPRINTF("\n Student GPA: %f ",PQ->Student_QUEUE[pos].GPA);
		for(int i=0;i<5;i++){
			DPRINTF("\n Student Course %d ID:  %d ",i+1,PQ->Student_QUEUE[pos].CourseID[i]);
		}

		pos=(pos+1)%MAX_QUEUE;
	}


}
int total_stud(QUEUE_t *BUFF){
	return BUFF->length;
}



QUEUE_Status delete_student(QUEUE_t *PQ,Student_info *std){


	int id;
	DPRINTF("Enter student ID :");
	scanf("%d",&id);

	int pos,s;
	for(pos=PQ->front,s=0;s<PQ->length;s++)
	{

		if (PQ->Student_QUEUE[pos].ID==id)
		{
			DPRINTF("FOUND \n");
			break;
		}
		pos=(pos+1)%MAX_QUEUE;
	}

	*std = PQ->Student_QUEUE[PQ->front];
	PQ->front=(PQ->front+1) %MAX_QUEUE;

	PQ->length--;

	return QUEUE_NO_ERROR;

}

void add_student_file(QUEUE_t *BUFF,Student_info std,FILE *fp){


	char c;
	int count=BUFF->length;

	if(fp){
		printf("DONE");
		while(!feof(fp)){

            printf("\n loop");
			int x=0;
			fscanf(fp,"%d" , &std.ID);
			/*for(int i=0; i<count; i++)
			{
				if(std.ID == BUFF->Student_QUEUE[i].ID)
				{
					printf("[ERROR] The student roll number already exists! (roll number: %d)\n", std.ID);
					x=1;
				}
				*/


				fscanf(fp,"%s %s %f %d %d %d %d %d" , std.fname,std.lname,&std.GPA,&std.CourseID[0],&std.CourseID[1],&std.CourseID[2],&std.CourseID[3],&std.CourseID[4]);
			//}
			printf("\nadding");


			if(x == 0){
				count++;
				BUFF->rear=(BUFF->rear+1) %MAX_QUEUE;
				BUFF->Student_QUEUE[BUFF->rear]=std;
				BUFF->length++;
			}



		}

	}

}

QUEUE_Status update_stud_info(QUEUE_t *PQ){


	int id;
	DPRINTF("Enter student ID :");
	scanf("%d",&id);

	int pos,s;
	for(pos=PQ->front,s=0;s<PQ->length;s++)
	{

		if (PQ->Student_QUEUE[pos].ID==id)
		{
			DPRINTF("FOUND \n");
			break;
		}
		pos=(pos+1)%MAX_QUEUE;
	}


	add_info(&PQ->Student_QUEUE[pos]);
	return QUEUE_NO_ERROR;
}






