#include "stdio.h"
#include "string.h"
#include "conio.h"

#define pi 3.14
#define Area(r) (pi*(r)*(r))

/*
struct student{
	 char name[50];
	 int roll;
	 float marks;
};
*/

/*
struct  Distance {
	int feet;
	float inch;

}d1,d2,sum;

*/

/*
struct complex{

	float real;
	float imag;
}x,y,z;

struct complex ADD(struct complex A, struct complex B)
{

	struct complex res;

	res.real=A.real+B.real;
	res.imag=A.imag+B.imag;

	return res;
}

*/

/*
struct students{

	int roll_num;
	char stud_name[50];
	int stdu_marks;

}stud[10];
*/

void main ()
{

/*	sudents info1
 *
 * int n;
	printf("Enter number of students ");
	fflush(stdout);
	scanf("%d",&n);

	while(n--){
		struct student s;
	  printf("\nEnter information of students :\n");
	  printf("Enter name :");
	  fflush(stdout);
	  scanf("%s",&s.name);
	  printf("Enter roll number :");
	  fflush(stdout);
	  scanf("%d",&s.roll);
	  printf("Enter marks :");
	  fflush(stdout);
	  scanf("%f",&s.marks);
	  printf("Displaying information: \n");

	  printf("name: %s\nRoll: %d\nMarks: %f",s.name,s.roll,s.marks);

	}
	*/

/*    feet and inches
 *
 * 	printf("Enter information for 1st distance\n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&d1.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d1.inch);
	printf("\nEnter information for 2nd distance\n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&d2.feet);
	printf("Enter inch:");
	fflush(stdout);
	scanf("%f",&d2.inch);

	sum.feet=d1.feet+d2.feet;
	sum.inch=d1.inch+d1.inch;

	if (sum.inch>12){

		sum.inch=sum.inch-12.0;
		++sum.feet;
	}
	printf("\nSum of distances=%d\'-%.1f\"",sum.feet,sum.inch);
*/

 /*  two complex numbers
	printf("For 1st complex number :\n");
	printf("Enter real and imaginary respectively : ");
	fflush(stdout);
	scanf("%f %f",&x.real,&x.imag);

	printf("For 2nd complex number :\n");
	printf("Enter real and imaginary respectively : ");
	fflush(stdout);
	scanf("%f %f",&y.real,&y.imag);
	z=ADD(x,y);
	printf("sum= %.1f + %.1fi",z.real,z.imag);

	*/

	/*   Students information
	printf("Enter information of students:\n");
    for (int i=0;i<10;i++)
   {
  	printf("Enter roll number");
  	fflush(stdout);
  	scanf("%d",&stud[i].roll_num);

  	printf("Enter name: ");
  	fflush(stdout);
  	scanf("%s",&stud[i].stud_name);

    printf("Enter Marks: ");
  	fflush(stdout);
  	scanf("%d",&stud[i].stdu_marks);

   }

    printf("Displaying information of students:\n");
        for (int i=0;i<10;i++)
       {
      	printf("information for  roll number: %d",stud[i].roll_num);
      	printf("Name: %s",stud[i].stud_name);
        printf(" Marks: %d",stud[i].stdu_marks);


       }

       */

	/*
	 * macros
	  int radius;
	  float area;
	  printf("Enter the radius: "); scanf("%d", &radius);
	  area=Area(radius);
	  printf("%.2f ",area);
   */

	/*output of program 6
	 *
	 * size of union =30
	 * size of structure 40
	 */








}
