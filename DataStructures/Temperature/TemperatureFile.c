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
	FILE *cfptr;
	float C,F;
	int choice;
	/* fopen opens file. Exit program if unable to create file */
	if((cfptr = fopen("output.txt","a+"))==NULL)
	{
 		printf("file could not opened for writing");
	}
	else
	{
		printf("The conversion Type as follows \n 1. Centigrade to Fahrenheit degress \n 2. Fahrenheit to Celsius degree \n");
		fprintf(cfptr,"The conversion Type as follows \n 1. Centigrade to Fahrenheit degress \n 2. Fahrenheit to Celsius degree \n");
		printf("Enter the Choice in number:");
		fprintf(cfptr,"Enter the Choice in number:");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter the Temperature in Celsius to convert to Fahrenheit degree:");
			fprintf(cfptr,"Enter the Temperature in Celsius to convert to Fahrenheit degree:");
			scanf("%f",&C);
			F=(C*9/5)+32;
			fprintf(cfptr,"The C to F is %.2f\n",F);
		}
		else
		{	
			printf("Enter the Temperature in Fahrenheit to convert to Temperature degrees:");
			fprintf(cfptr,"Enter the Temperature in Fahrenheit to convert to Temperature degrees:");
			scanf("%f",&F);
			C=(F-32)*5/9;
			fprintf(cfptr,"The C to F is %.2f\n",C);
		}
	}
	fclose(cfptr);
return 0;
}


