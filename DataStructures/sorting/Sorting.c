# include<stdio.h>
#include<stdlib.h>
#define SIZE 40
void bubblesort(int array[], int size);
void insertsort(int array[], int size);
void selectionsort(int array[], int size);
void shellsort(int array[], int size);
void printarray(int arraynum[], int size);
void swap(int *array1, int *array2);
int main(int argc, char *argv[])
{
	/* Opening and Closing File Pointers */
	FILE *iptr, *fptr;
	int i, j,choice;
	int number[SIZE];
	//validate the arguments not equal to 3
    if(argc!=2)
    {
        printf("Usage:  %s  inputFileName   outputFileName\n", argv[0]);
        exit(1);
    }
/*if entered arguments are valid, open the file read the record from argv[1] file  
and split the records as number, and store them in the array.*/
    else
    {
        if((iptr=fopen(argv[1], "r"))==NULL)
        {
			printf("Error in opening files...");
        }
        else
        {
			for(i=0;i<40;i++)
			{
				fscanf(iptr, "%d,", &number[i]);
			}
		}
	
		fclose(iptr);//closing of reading file
	}
	printf("Enter the choice in which method you want your array to be sorted\n");
	printf("****SIMPLE SORT****\n1.BubbleSort \n2.InsertionSort \n3.SelectionSort\n4.ShellSort\n");
	printf("enter your choice\n");
	scanf("%d", &choice);
	printf("The array before sorting is \n");
	printarray(number, SIZE);
	switch(choice)
	{
 	case 1:
		bubblesort(number, SIZE);
		break;
	case 2:
		insertsort(number, SIZE);
		break;
	case 3:
		selectionsort(number, SIZE);
		break;
	case 4:
		shellsort(number, SIZE);
		break;
	}
return 0;
}	

void printarray(int arraynum[], int size)
{
	int i;
	printf("The Array Elements  after sorting is \n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", arraynum[i]);
	}
}


void bubblesort(int array[], int size)
{
	int j, pass;
	//sort the array by comparing the adjacent element and swap the array element if its larger
	printf("The array after bubble sort is\n")
	for(pass=0;pass<size-1;pass++)
	{
		for(j=0;j<size-1;j++)
		{
			if(array[j]>array[j+1])
			{
				swap(&array[j], &array[j+1]);
			}
		}
	}
	printarray(array,size);
}

void insertsort(int array[], int size)
{
	int j, i;
	for(i=1;i<size;i++)
	{
		j=i;
		while(j>0 && array[j-1]>array[j])
		{
			swap(&array[j], &array[j-1]);
			j=j-1;
			printf("The array sorted after each pass is \n");
		}
	}
			printarray(array, size);
}


void selectionsort(int array[], int size)
{
	int i, j;
	int min;
	for(j=0;j<size-1;j++) 
	{
   		min=j;
    for(i=j+1;i<size;i++) 
	{
        if(array[i]<array[min]) 
		{
            min=i;
        }
    }
    if(min!=j) 
	{
    	swap(&array[j],  &array[min]);
	}

	}	
	printarray(array, size);
}


void shellsort(int array[],int size)
{
    int i = 0,  j = 0, k = 0, mid = 0;
    for (k = size / 2;k > 0;k /= 2)
    {
        for (j = k;j < size;j++)
        {
            for (i = j - k;i >= 0;i -= k)
            {
                if (array[i + k] >= array[i])
                {
                    break;
                }
                else
                {
                    swap(&array[i],  &array[i+k]);
                }
            }
        }
    }
	printarray(array, size);
    return ;
}


void swap(int *array1, int *array2)
{
	int tmp;
	tmp = *array1;
	*array1 = *array2;
	*array2 = tmp;
	return;
}

