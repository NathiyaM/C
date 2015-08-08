#include<stdio.h>
int main()
{
int choice=0;
printf("Welcome to sorting program\n\t1.Title\n\t2.Rank3.\n\t3.Date\n\t4.Stars\n\t5.Likes\n");
while(choice!=-1)
{
	printf("enter your choice between 1 to 5");
	scanf("%d",&choice);
	if((choice>=1) && (choice<=5))
	{
	printf("you entered valid choice%d\n",choice);
	break;
	}
	else if(choice>5)
	{
	printf("you have entered an invalid choice.Try again\n");
	continue;
	}
	else
	{
	printf("you have entered an invalid choice,Try again\n");
	continue;
	}
}
return 0;
}

	

