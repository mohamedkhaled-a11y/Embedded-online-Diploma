
#include "stdio.h"

void main ()
{

	//EX1
	printf("c programming\n");


	printf("###############################\n\n");

	//EX2
	int x;
	printf("Enter a integer : ");
	fflush(stdout);
	scanf("%d",&x);
	printf("you entered : %d \n",x);

	printf("####################################################\n");

	//EX3
	int n1,n2;
	printf("Enter two Entegers : ");
	fflush(stdout);
	scanf("%d%d",&n1,&n2);
	printf("sum : %d \n",n1+n2);
	printf("###################################################\n");

	//EX4
	float k,h;
	printf("Enter two numbers : ");
	fflush(stdout);
	scanf("%f%f",&k,&h);
	printf("product : %f \n",k*h);
	printf("###################################################\n");

	//EX5

	char c;
	printf("Enter character : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&c);
	printf("Ascii value of %c is : %d \n",c,c);
	printf("#############################################################\n");

	//EX6
	float a,b,temp;
	printf("Enter value of a : ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %f \n",a);
	printf("After swapping, value of b = %f \n",b);

	//EX7

	float r,d;
	printf("Enter value of r : ");
	fflush(stdout);
	scanf("%f",&r);
	printf("Enter value of d ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&d);
	r=r+d;
	d=r-d;
	r=r-d;
	printf("After swapping, value of r = %f \n",r);
	printf("After swapping, value of d = %f \n",d);


}


