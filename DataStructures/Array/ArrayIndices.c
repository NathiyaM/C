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
/*			Assignment No:3														*/
/*																				*/
/*			Topic:Array															*/
/*																				*/
/*			FileName:ArrayIndices.c												*/
/*			Date of the Program:10.24.2015										*/
/*			Objective:Find the indices of the input elements read on prompt 	*/
/*			using the array after all activities,display the array elements 	*/
/*			in the original order,diplay the array in the reverese order		*/
/*																				*/
/*																				*/
/*																				*/
/********************************************************************************/  

/* Preprocessor Directives */
#include<stdio.h>
#define SIZE 40
void sort(int array[],int size);//function prototype
void indices(int array[],int size);//function prototype
int main()
{
	//Array Declaration
	int array_element[SIZE],i;
	//Get the array elements from the standard input 
	printf("Enter the array of 40 elements by spaces\n");
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&array_element[i]);
	}
	//Display the array in original order.
	printf("The array elemets in original order is \n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d\t",array_element[i]);
	}
	//Display the array in the reverese order.
	printf("\nThe array elements in Reverse order is \n");
	for(i=SIZE-1;i>=0;i--)
	{
		printf("%d\t",array_element[i]);
	}
	printf("\n");
	sort(array_element,SIZE);//function calling
	indices(array_element,SIZE);//function calling
/* The array in sorted Order as follows
	for(i=0;i<SIZE;i++)
	{
	printf("%d\t",array_element[i]);
	} */
return(0);
}
//function definition of sort
void sort(int array[],int size)
{
	int j,pass,tmp;
	//sort the array by comparing the adjacent element and swap the array element if its larger
	for(pass=0;pass<size-1;pass++)
	{
		for(j=0;j<size-1;j++)
		{
			if(array[j]>array[j+1])
			{
				tmp=array[j];
				array[j]=array[j+1];
				array[j+1]=tmp;
			}
		}
	}
	//Display the elements in the sorted order
	printf("The Array Elements in the sorted order as follows:\n");
	for(j=0;j<size;j++)
	{
		printf("%d\t",array[j]);
	}
	printf("\n");
}

//function definition of indices

void indices(int array[],int size)
{
	int i,j,a[9];
	/* prompt the user to enter the array element,store it in the another list of array
	   to process and produce the index once at a time */
	printf ("enter the array of element one at a time ,to give the index of the element\n");
	for(i=0;i<9;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	/* Parse the each element which we get from the user with each element in the original sorted 
	 array,if we find the element in the original element ,print the indices of the array element*/
	for(i=0;i<9;i++)
	{
		for(j=0;j<size;j++)
		{
			if(a[i]==array[j])
			{
				printf("The index of %d\t is %d\n",a[i],j);
			}
		}
	}
}

	

