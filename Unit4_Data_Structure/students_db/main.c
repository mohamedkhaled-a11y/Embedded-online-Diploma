#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct Student_data
{
     int ID;
     char name[40];
     float Height;
};


typedef struct Student_Node{

	struct Student_data student;
	struct Student_Node *PTR_to_NEXT_STUD;
}Student_Node;

Student_Node *GPTR_first_stud=NULL;

/*void Add_Student();

void delete_Student();

void view_Students();

void delete_all();


void FillRecord(Student_Node *stud);

*/



void FillRecord(Student_Node *stud)
{
char temp[40];
printf("Enter Student ID: ");
gets(temp);
stud->student.ID=atoi(temp);
printf("Enter Student Name: ");
gets(stud->student.name);
printf("Enter Student Height: ");
gets(temp);
stud->student.Height=atof(temp);

}



void Add_Student()
{

	Student_Node *pNewStudent;
	//Check if the list is empty or not
	if (GPTR_first_stud==NULL)
	{
	pNewStudent= (Student_Node *)malloc(sizeof(Student_Node));
	GPTR_first_stud=pNewStudent;

	}
	else {
	Student_Node *PTR_Nav=GPTR_first_stud;
	while(PTR_Nav->PTR_to_NEXT_STUD)
		PTR_Nav=PTR_Nav->PTR_to_NEXT_STUD;

	pNewStudent= (Student_Node *)malloc(sizeof(Student_Node));
	PTR_Nav->PTR_to_NEXT_STUD=pNewStudent;

	}

	//Fill the record

	FillRecord(pNewStudent);

	pNewStudent->PTR_to_NEXT_STUD=NULL;

}

int DeleteRecord()
{
    int temp;
    printf("Enter ID:\n");
    scanf("%d",&temp);

    if(GPTR_first_stud)
    {
        Student_Node *pSelected;
        Student_Node *pPrev=NULL;
        while(pSelected){

        if(pSelected->student.ID==temp){

        if(pPrev)   //the first student was not match the selected id
        {

         pPrev->PTR_to_NEXT_STUD=pSelected->PTR_to_NEXT_STUD;
        }
        else // the first student is the selected
        {
            GPTR_first_stud=pSelected->PTR_to_NEXT_STUD;

        }
        free(pSelected);
        return 1;

        }
        pPrev=pSelected;
        pSelected=pSelected->PTR_to_NEXT_STUD;

        }
    }

 printf("ID Not found \n");
 return 0;

}




void main(void)
{

char temp;
printf("Enter case:\n");
scanf("%c",&temp);


while (1){
switch(temp)
{

case 'a':
    Add_Student();
    break;
case 'b':
    DeleteRecord;
    break;

}
}
}
