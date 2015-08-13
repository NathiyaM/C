#include<stdio.h>
#define SIZE 10
int main()
{
	float number[SIZE]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	float *nptr;
	int i;
	for(i=0;i<SIZE;i++)
	{
	printf("%.1f\t The number of array are\n",number[i]);
	}
	nptr=number;
	for(i=0;i<SIZE;i++)
	{
	printf("%.1f\t pointer offset notation with pointer\n",*(nptr+i));
	}
	for(i=0;i<SIZE;i++)
	{
	printf("%.1f\t pointer offset notation with array\n",*(number+i));
	}
	for(i=0;i<SIZE;i++)
	{
	printf("%.1f\t point subscription\n",nptr[i]);
	}
	printf("The fourth element in the array using array subscription is %.1f\n",number[3]);
	printf("The fourth element in the array using pointer subscription is %.1f\n",nptr[3]);
	printf("The fourth element in the array using pointer notation is %.1f\n",*(nptr+3));
	printf("The fourth element in the array using pointer notation using array name is %.1f\n",*(number+3));
	printf("The address and value of 9th element in the array %.1f\n",*(nptr+8));
	nptr = nptr+5;
	printf("The value of array at 1st element is%.1f\n",*(nptr-4));
	return 0;
}
