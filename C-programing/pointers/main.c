#include "stdio.h"

void PRINT_alpha()
{
/*
char alpha[27];
int i;
char *ptr_alpha;

ptr_alpha=alpha;
for (i=0;i<26;i++)
{
	*ptr_alpha=i+'A';
	ptr_alpha++;
}
ptr_alpha=alpha;

printf("Alphabets Are :\n");

for (i=0;i<26;i++)
{
	printf("%c ",*ptr_alpha);
	ptr_alpha++;
}
printf("\n");
*/
}

void handl_ptr()
{ /*
	int m=29;
	printf("address of m : %p\n value of m : %d\n",&m,m);
	int *ab;
	ab=&m;
	//printf("\n");
	printf("\nNow ab is assigned with the address of m.\n");

	printf("\n Address of pointer ab: %p\n Content of pointer ab: %d\n ",ab,*ab);

	m=34;
	printf("\nThe value of m assigned to 34 now\n.");
	printf("\n Address of pointer ab: %p\n Content of pointer ab: %d\n ",ab,*ab);
	*ab=7;
	printf("\nThe pointer variable ab is assigned with the value 7 now\n");
	printf("\naddress of m : %p\n value of m : %d\n",&m,m);
*/
}

void str_rev()

{
	/*
int i=0;
char str[10];
char *str_ptr;
str_ptr=str;
scanf("%s",str_ptr);
fflush(stdout);
	//str_ptr=&str[10];

while(*str_ptr)
   {
	 str_ptr++;
	 i++;
   }


for (i;i>=0;i--)
   {
    printf("%c",*str_ptr);
    str_ptr--;
   }
*/
}



void rev_arr()
{
	/*
int siz;
printf("Input the number of elements to store in the array (max 15) :");
fflush(stdout);
scanf("%d",&siz);
int arr[siz];
printf("Input %d number of elements in the array :\n",siz);
for (int i=0;i<siz;i++)
{
	printf("element-%d ",i+1);
	fflush(stdout);
	scanf("%d",&arr[i]);
}

int *arr_pt=&arr[siz-1];
printf("elemnets of array in reverse order are \n");

for (int i=siz-1;i>=0;i--)
{
	printf("element-%d : %d\n",i+1,*arr_pt);
	arr_pt--;
}
*/
}

void str_ptr()
{
	/*

	typedef struct  {
		char Name[10];
		int id;
	}Employees;

	Employees emp1={"Jhon",1001},emp2={"Alex",1002},emp3={"Taylor",1003};

	//initialize array of pointer points to each employee in struct
	Employees *emp_arr[3]={&emp1,&emp2,&emp3};

	//initialize pointer to array of pointers
	Employees *(*emp_ptr)[3]=emp_arr;

	//Name of emp1
	printf("Exmployee Name %s\n",(**(*emp_ptr+1)).Name);
	printf("Exmployee ID %d\n",(**(*emp_ptr+1)).id);
*/
}


int main()
{
//handl_ptr;
//PRINT_alpha();
//str_rev();
//rev_arr();
//str_ptr();

return 0;
}
