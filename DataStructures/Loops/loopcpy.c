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
	int count=0,lexit=0;//Declare the variable to count the variable entered by the user
	while(lexit!=-1)
	{
		printf("Enter the scores of the individual student one by one followed by the spaces\n");
		scanf("%f",&scores);
		count+=1;
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
		printf("Enter -1 if you're done with entering the student scores or press any key to continue:");
		scanf("%d",&lexit);
	}
	printf("The Minimum Score is %.2f\n",min);
	printf("The Maximum Score is %.2f\n",max);
	printf("The Average score is %.2f\n",average);
	printf("The Average score is %.2f\n",total);

}
		
		
		

