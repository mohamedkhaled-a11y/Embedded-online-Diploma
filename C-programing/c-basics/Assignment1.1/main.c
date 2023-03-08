

#include "stdio.h"

void main()
{
	//Ex1 even or odd
/*	int n;
	printf("Enter an integer you want to check : ");
	fflush(stdout);
	scanf("%d",&n);
	if (n%2==0)
	  printf("%d is even ",n);
	else
		printf("%d is odd ",n);
	*/

	//EX2
	/*char v;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&v);
	if (v=='a'||v=='o'||v=='e'||v=='u'||v=='i')
		printf("%c is a vowel",v);
	else
		printf("%c is constant ",v);
   */

	//EX3
/*
	float x,y,z;
	printf("Enter three numbers ");
	fflush(stdin);fflush(stdout);
	scanf("%f%f%f",&x,&y,&z);
	if (x>=y && x>=z)
		printf("Largest number is %f ",x);
	else if (y>=x && y>=z)
		printf("Largest number is %f ",y);
	else if (z>=y &&z>=x)
		printf("Largest number is %f ",z);
	*/

	//EX4
	/*float num;
	printf("Enter a number : ");
	fflush(stdout);
	scanf("%d",&num);
	if (num>0)
		printf("%f is positive ",num);
	else if (num<0)
		printf("%f is negative ",num);
	else if (num==0)
		printf("you entered zero");
	*/


	//EX5

	/*
	 char alph;
	    printf("Enter a character: ");
	    fflush(stdin);fflush(stdout);
	    scanf("%c", &alph);
	    if ((alph >= 'a' && alph <= 'z') || (alph >= 'A' && alph <= 'Z'))
	        printf("%c is an alphabet.", alph);
	    else
	        printf("%c is not an alphabet.", alph);
*/


	//EX6
	/*int N,sum;
	printf("ENTER number: ");
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		sum+=i;
	}
	printf("SUM = %d,sum);
*/


	//EX7
/*	int k,fac=1;
	printf("ENTER number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&k);
	if (k<0)
		printf("ERROR!! factorial of negative number doesn't exist");
	else
	    for (int i=1;i<=k;i++){
		   fac*=i;
}
	printf("factorial = %d",fac);
	*/



	//EX8

	/*
	  char op;
	  float first, second;
	  printf("Enter an operator (+, -, *, /): ");
	  scanf("%c", &op);
	  printf("Enter two operands: ");
	  scanf("%lf %lf", &first, &second);

	  switch (op) {
	    case '+':
	      printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
	      break;
	    case '-':
	      printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
	      break;
	    case '*':
	      printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
	      break;
	    case '/':
	      printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
	      break;
	    // operator doesn't match any case constant
	    default:
	      printf("Error! operator is not correct");

	*/
}




