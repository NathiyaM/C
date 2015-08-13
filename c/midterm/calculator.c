#include<stdio.h>
float addition(float number1,float number2);
float subtraction(float number1,float number2);
float multiplication(float number1,float number2);
float division(float number1,float number2);
int main()
{
int choice=6;
float num1,num2;
while(choice!=-1)
{
printf("Welcome to Nathiya's Handy Calculator\n\t1.Addition\n\t2.Subtraction\n\t3.Multiplication\n\t4.Division\n\t5.Exit\n");
while(choice<1 || choice>5)
{
	printf("enter your choice between 1 to 5");
	while(scanf("%d",&choice)!=1)
	{
		while (getchar() != '\n')
 		continue;
 		printf("\nYou have entered an invalid choice. Try again.");	
	}
	if(choice<1 || choice>5)
	printf("You have entered the number between 1 and 5.Try again\n");
}
	switch(choice)
	{
	case 1:
		printf("enter the two number to add:");
		while(scanf("%f%f",&num1,&num2)!=2)
		{
			while(getchar()!='\n')
			continue;
			printf("Error reading your inputs try again:");
		}	
		printf("The result of adding %5.2f and %5.2f is %5.2f",num1,num2,addition(num1,num2));
		choice=6;
		break;
	case 2:
		printf("enter the two number to subtract:");
		while(scanf("%f%f",&num1,&num2)!=2)
		{	
			while(getchar()!='\n')
			continue;
			printf("Error reading your inputs try again:");
		}
		printf("The result of dividing %5.2f and %5.2f is %5.2f",num1,num2,subtraction(num1,num2));
		choice=6;
		break;
	case 3:
		printf("enter the two number to multiply:");
		while(scanf("%f%f",&num1,&num2)!=2)
		{
			while(getchar()!='\n')
			continue;
			printf("Error reading your inputs try again:");
		}
		printf("The result of dividing %5.2f and %5.2f is %5.2f",num1,num2,multiplication(num1,num2));
		choice=6;
		break;
	case 4:
		printf("enter the two number to division:");
		while(scanf("%f%f",&num1,&num2)!=2)
		{
			while(getchar()!='\n')
			continue;
			printf("Error reading your inputs try again:");
		}
		printf("The result of dividing %5.2f and %5.2f is %5.2f",num1,num2,division(num1,num2));
		choice=6;
		break;
	case 5:
		choice = -1;
		break;
}
}
}
float addition(float number1,float number2)
{
return number1+number2;
}
float subtraction(float number1,float number2)
{
return number1-number2;
}
float multiplication(float number1,float number2)
{
return number1*number2;
}
float division(float number1,float number2)
{
return number1/number2;
}
	

