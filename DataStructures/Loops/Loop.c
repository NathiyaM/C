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
/*			Assignment No:2														*/
/*																				*/
/*			Topic:Student Maximum,Minimum,Average Score							*/
/*																				*/
/*			FileName:Temperature.c												*/
/*			Date of the Program:10.24.2015										*/
/*			Objective:Find the Maximum , Minimum ,Average Score of the single	*/
/*			Student without using function and Array.							*/
/********************************************************************************/  

/* Preprocessor Directives */
#include<stdio.h>
int main()
{
	float average,scores,max=0,total=0,min=0;//Variable Declaration
	int count,lexit=0;//Declare the variable to count the variable entered by the user
	printf("Enter the number of scores you are going to enter\n");
	scanf("%d",&count);
	printf("Enter the scores one at a time\n");
	while(lexit<count)
	{
		scanf("%f",&scores);
		lexit++;
		total+=scores;
		if(scores>max)
		{
			max=scores;
		}
		if(min==0)
		{
			min=scores;
		}
		else if(scores<min)
		{
			min=scores;
		}
			
		average=total/count;
	}
	printf("The Minimum Score is %.2f\n",min);
	printf("The Maximum Score is %.2f\n",max);
	printf("The Average score is %.2f\n",average);

}
		
		
		

