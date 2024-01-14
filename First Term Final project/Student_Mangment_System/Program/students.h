/*
 * students.h
 *
 *  Created on: Jul 20, 2023
 *      Author: XPRISTO
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef unsigned char uint8_t ;
typedef unsigned int uint32_t ;



#define element_type uint8_t
typedef struct student_info{

	unsigned int ID;
	char fname[50];
	char lname[50];
	float GPA;
	int CourseID[5];
}Student_info;


typedef struct {
	uint32_t length;
	 int front;
	 int rear;
	Student_info Student_QUEUE[55];

}QUEUE_t;


typedef enum{
	QUEUE_NO_ERROR,
	QUEUE_FULL,
	QUEUE_EMPTY,
	QUEUE_NULL,
}QUEUE_Status;





QUEUE_Status Queue_init(QUEUE_t *BUFF);
void add_student_file(QUEUE_t *BUFF,Student_info std,FILE *fp);
QUEUE_Status add_student_manualy(QUEUE_t *BUFF,Student_info stud);
void find_ID(QUEUE_t *BUFF);
void find_fname(QUEUE_t *BUFF);
void find_course(QUEUE_t *BUFF);
int total_stud(QUEUE_t *BUFF);
QUEUE_Status delete_student(QUEUE_t *PQ,Student_info *std);
QUEUE_Status update_stud_info(QUEUE_t *PQ);
void show_students(QUEUE_t *BUFF);
void add_info(Student_info *stud);







#endif /* STUDENTS_H_ */
