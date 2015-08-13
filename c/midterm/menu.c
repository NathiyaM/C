#include<stdio.h>
int  ViewMenu();
int main()
{
	int choice;
	choice=ViewMenu();
	printf("you entered a valid choice%d",choice);
	printf("Thank you for entering your choice\n");
	return 0;
}


int ViewMenu()
{
int choice;
printf("Welcome to sorting program\n\t1.Title\n\t2.Rank3.\n\t3.Date\n\t4.Stars\n\t5.Likes\n");
do{

	printf("enter your choice between 1 to 5");
	while(scanf("%d",&choice)!=1)
	{
	while (getchar() != '\n')
 	continue;
 	printf("\nYou have entered an invalid choice. Try again.");	
	}
	if(choice<1 || choice>5)
	printf("You have not entered the number between 1 and 5.Try again\n");
}
while(choice<1 || choice>5);
return choice;
}

	

