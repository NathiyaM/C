#include<stdio.h>
int main()
{
	int a,b;
	float num1,num2;
	printf("Please enter float number seperated by space and press enter:\n");
	while(scanf("%f%f",&num1,&num2)!=2)
	{
		while(getchar()!='\n')
		continue;
		printf("You have invalid choice,Try again");
	}
	printf("The numbers are %.2f%.2f",num1,num2);
}

