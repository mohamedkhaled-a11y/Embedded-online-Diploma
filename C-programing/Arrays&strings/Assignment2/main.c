/*
 * main.c
 *
 *  Created on: Feb 14, 2023
 *      Author: XPRISTO
 */

#include "stdio.h"

void main()
{


/*
 * EX1 SUMMTION
 *
 * float a[2][2];
	float b[2][2];
	float sum[2][2];

	printf("Enter elements of First matrix \n");
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf("Enter a%d%d :",i+1,j+1);
			fflush(stdout);fflush(stdin);
			scanf("%f",&a[i][j]);

		}
	}
	printf("Enter elements of Second matrix \n");
		for (int i=0;i<2;i++)
		{
			for (int j=0;j<2;j++)
			{
				printf("Enter a%d%d :",i+1,j+1);
				fflush(stdout);fflush(stdin);
				scanf("%f",&b[i][j]);

			}
		}

		for (int i=0;i<2;i++)
				{
					for (int j=0;j<2;j++)
					{
						sum[i][j]=a[i][j]+b[i][j];
					}
				}
		for (int i=0;i<2;i++)
						{
							for (int j=0;j<2;j++)
							{
								printf("%.1f \t",sum[i][j]);
							}
							printf("\n");
						}*/

/*
 * EX2 Average
 *
 * int NUM;
printf("Enter numbers of data :");
fflush(stdout);fflush(stdin);
scanf("%d",&NUM);
float data[NUM];
float sum=0;
for (int i=0;i<NUM;i++ )
	{
		printf("Enter Number : ");
		fflush(stdout);fflush(stdin);
		scanf("%f",&data[i]);

	}
for (int i=0;i<NUM;i++ )
		{

			sum+=data[i];
		}

printf("Average = %f",sum/NUM);
*/


	/*
	 * EX3 Matrix transpose
	 *
	 * int r, c;
	  printf("Enter rows and columns: ");
	  fflush(stdout);
	  scanf("%d %d", &r, &c);
	  int a[r][c];
	  int transpose[r][c];

	  // asssigning elements to the matrix
	  printf("\nEnter matrix elements:\n");
	  for (int i = 0; i < r; ++i)
	  for (int j = 0; j < c; ++j) {
	    printf("Enter element a%d%d: ", i + 1, j + 1);
	    fflush(stdout);fflush(stdin);
	    scanf("%d", &a[i][j]);
	  }

	  // printing the matrix a[][]
	  printf("\nEntered matrix: \n");
	  for (int i = 0; i < r; ++i){
	  for (int j = 0; j < c; ++j) {
	    printf("%d  ", a[i][j]);
	  }
	    printf("\n");
	}
	  // computing the transpose
	  for (int i = 0; i < r; ++i){
	  for (int j = 0; j < c; ++j) {
	    transpose[j][i] = a[i][j];
	  }
	  }
	  // printing the transpose
	  printf("\nTranspose of the matrix:\n");
	  for (int i = 0; i < c; ++i)
	  {


	  for (int j = 0; j < r; ++j) {
	    printf("%d  ", transpose[i][j]);
	   // if (j == r - 1)
	  }
	  printf("\n");
	  }
*/

/*
 * EX4 insert element in array
 *
 * int num_of_elements;
printf("Enter number of elements in array :");
fflush(stdout);
scanf("%d",&num_of_elements);
int arr[num_of_elements];
for (int i=0;i<num_of_elements;i++)
{
	scanf("%d",&arr[i]);
	}

int element,location;
printf("Enter element you want: ");
fflush(stdout);
scanf("%d",&element);
printf("Enter location : ");
fflush(stdout);
scanf("%d",&location);

arr[location]=element;

for (int i=0;i<num_of_elements;i++)
{
	printf("%d \t",arr[i]);
	}

*/


	//EX 5: searching in Arrays

/*
	int size ,m;
	printf("Enter number of elements in array :");
	fflush(stdout);
	scanf("%d",&size);
	int arr_s[size];
	int loc;
	for (int i=0;i<size;i++)
			{
			scanf("%d",&arr_s[i]);
			}
	for (int i=0;i<size;i++)
		        {
				printf("%d \t",arr_s[i]);
				}


	printf("\n Enter elements to be searched :");
	fflush(stdout);
	scanf("%d",&m);
	for (int i=0;i<size;i++)
			        {
					if (m==arr_s[i])
					{
						loc=i;
						break;
					}
					}


printf("Number found at location = %d",loc);


*/


	//strings
/*	char text[100];
	char Letter;
	int freq=0;
	printf("Enter your string :");
	fflush(stdout);fflush(stdin);
	gets(text);
	printf("Enter Letter :");
	fflush(stdout);fflush(stdin);
	scanf("%c",&Letter);
	for (int i=0;i<sizeof(text);i++){
		if (Letter==text[i]) freq+=1;
	}

printf("The letter you entered is frequently %d times",freq);

*/
}





