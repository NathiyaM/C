#include<stdio.h>
//funtion prototype declaration
void ViewMenu(void);
int getchoice(void);
void addition(void);
void subtraction(void);
void multiplication(void);
void division();
int  PressEnterToContinue();
//start of the program
int main()
{
	int choice;
	float num1,num2;
	while(choice!=-1)
	{
		ViewMenu();//get the menu options 
		choice=getchoice();//get the choice
		switch(choice)
		{
		case 1:
			addition();
			choice = PressEnterToContinue();
			break;
		case 2:
			subtraction();
			choice = PressEnterToContinue();
			break;
		case 3:
			multiplication();
			choice = PressEnterToContinue();
			break;
		case 4:
			division();
			choice = PressEnterToContinue();
			break;
		case 5:
			choice = -1;
			printf("Thank you for using Nathiya's Handy Calculator\n");
			break;
	}
}
}

/*function definitions*/
//list of operations to perform
void ViewMenu(void)
{
	printf("\n Welcome to Nathiya's Handy Calculator\n");
	printf("\t1.Addition\n\t2.Subtraction\n\t3.Multiplication\n\t4.Division\n\t5.Exit\n");
}

//gets the choice from the user to perform calculations

int getchoice(void)
{
	int choice;
	printf("what would you like to do? ");
	do
	{
		while(scanf("%d",&choice)!=1)
		{
			while (getchar() != '\n')
 			continue;
 			printf("\nThat is not a invalid choice,Please re-enter");	
		}
		if(choice<1 || choice>5)
 		printf("\nThat is not a invalid choice,Please re-enter");	
	}while(choice<1 ||choice>5);
}
//Addition operation
void addition(void)
{
	float num1,num2;
	printf("Enter the two number to add:");
	while(scanf("%f%f",&num1,&num2)!=2)
	{	
		while(getchar()!='\n')
		continue;
		printf("\nError reading your inputs try again:");
	}
	printf("The result of addition is %5.2f and %5.2f is %5.2f\n",num1,num2,num1+num2);
}
//subtraction
void subtraction(void)
{
	float num1,num2;
	printf("Enter the two number to subtract:");
	while(scanf("%f%f",&num1,&num2)!=2)
	{	
		while(getchar()!='\n')
		continue;
		printf("\nError reading your inputs try again:");
	}
	printf("The result of subtraction is %5.2f and %5.2f is %5.2f\n",num1,num2,num1-num2);

}
//multiplication
void multiplication(void)
{
	float num1,num2;
	printf("Enter the two number to multiply:");
	while(scanf("%f%f",&num1,&num2)!=2)
	{	
		while(getchar()!='\n')
		continue;
		printf("Error reading your inputs try again:\n");
	}
	printf("The result of multiplication  is %5.2f and %5.2f is %5.2f\n",num1,num2,num1*num2);
}

//Division Operation
void division(void)
{		
	float num1,num2=0;
	printf("Enter the two number to division:");
	while(num2==0)
	{
		while(scanf("%f%f",&num1,&num2)!=2)	
		{
			while(getchar()!='\n')
			continue;
			printf("Error reading your inputs try again:");
		}
		if(num2==0)
		{
			printf("You can't divide by zero,please reenter two numbers\n");
			continue;
		}
		else
		{	
			printf("The result of subtraction is %5.2f and %5.2f is %5.2f\n",num1,num2,num1/num2);
			break;
		}
	}
}

//wait for key to perform next calculation	
int PressEnterToContinue(void)
{ 
	printf("Press Enter Key to Continue...");
    char c = getchar();
    c = getchar();
   	if(c != '\n')
    {
		printf("Going to Exit \n");
		return -1;
	}
		return 1;
    
}
