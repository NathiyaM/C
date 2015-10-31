/********************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension,Santa Cruz                   	*/
/*                                                                              */
/*                                                                              */
/* 			Advanced C Programming                                           	*/
/*                                                                              */
/* 			Instructor :Rajainder A.Yeldandi									*/
/*                                                                              */
/* 			Author:Nathiya Meganathan											*/
/*																				*/
/*			Assignment No:1														*/
/*																				*/
/*			Topic:Temperature													*/
/*																				*/
/*			FileName:Temperature.c												*/
/*			Date of the Program:10.24.2015										*/
/*			Objective:Conversion of Temperature in Centigrade or				*/
/*			Celsius to Fahrenheit degrees and Fahrenheit to Celsius degree		*/
/********************************************************************************/  

/* Preprocessor Directives */

#include<stdio.h>
/*function main begins program execution*/
int main()
{
	float C,F;
	int choice=0;
	/*Sect the option for conversion */
	printf("The conversion Type as follows \n 1. Centigrade to Fahrenheit degress \n 2. Fahrenheit to Celsius degree \n 3. Exit\n");
	printf("Enter the Choice in number:");
	scanf("%d",&choice);
	//Enter the loop if the choice enters by the user is not equal to -1
	while(choice!=-1)
	{
	//check for the condition using the choice,evaluate the conversion by using the formula.
	if(choice==1)
	{
		printf("Enter the Temperature in Celsius to convert to Fahrenheit degree:");
		scanf("%f",&C);
		F=(C*9/5)+32;
		printf("The C to F is %.2f\n",F);
	}
	else if(choice==2)
	{	
		printf("Enter the Temperature in Fahrenheit to convert to Temperature degrees:");
		scanf("%f",&F);
		C=(F-32)*5/9;
		printf("The C to F is %.2f\n",C);
	}
	//The program will exit if the user enter 3 or anyother choice
	else
	{
		printf("Going to exit....\n");
		exit(0);
	}
	printf("The conversion Type as follows \n 1. Centigrade to Fahrenheit degress \n 2. Fahrenheit to Celsius degree \n 3. Exit");
	printf("Enter the Choice in number:");
	scanf("%d",&choice);
	}
return 0;
}

