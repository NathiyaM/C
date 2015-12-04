#include<stdio.h>
#include<stdlib.h>
#define SIZE 40
void bubblesort(int array[], int size);
void insertsort(int array[], int size);
void selectionsort(int array[], int size);
void shellsort(int array[], int size);
void quicksort(int x[],int first,int last);
void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
void heapsort(int a[],int n);
void heapify(int a[],int n);
void adjust(int a[],int n);
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
	printf("1.Simple Sort\n 2.Advance Sort\n");
    printf("enter your choice\n");
	scanf("%d", &choice);
	switch(choice)
	{
	   case 1:
	    printf("****SIMPLE SORT****\n1.BubbleSort \n2.InsertionSort \n3.SelectionSort\n4.ShellSort\n");
	    printf("enter your choice\n");
	    scanf("%d", &choice);
	    printf("The array before sorting is \n");
	    printarray(number, SIZE);
    	switch(choice)
    	{
        	case 1:
                bubblesort(number, SIZE);
                printf("The Array Elements  after sorting is \n");
                printarray(number,SIZE);
            	break;
        	case 2:
                insertsort(number, SIZE);
                printf("The Array Elements  after sorting is \n");
                printarray(number,SIZE);
                break;
            case 3:
                selectionsort(number, SIZE);
                printf("The Array Elements  after sorting is \n");
                printarray(number,SIZE);
                break;
            case 4:
                shellsort(number, SIZE);
                printf("The Array Elements  after sorting is \n");
                printarray(number,SIZE);
                break;
    	}
    	break;
        case 2:
            printf("*****Advanced Sort *****\n1.Quick Sort \n 2.Heap Sort \n 3.Merge Sort \n");
            printf("enter your choice\n");
	        scanf("%d", &choice);
	        printf("The array before sorting is \n");
	        printarray(number, SIZE);
            switch(choice)
    	    {
    	        case 1:
    	            quicksort(number,0,SIZE-1);
    	            printf("The Array Elements  after sorting is \n");
    	            printarray(number,SIZE);
    	            break;
    	       case 2:
    	            heapsort(number,SIZE);
    	            printf("The Array Elements  after sorting is \n");
    	            printarray(number,SIZE);
    	            break;
    	       case 3:
    	            partition(number,0,SIZE-1);
    	            printf("The Array Elements  after sorting is \n");
    	            printarray(number,SIZE);
    	            break;
    	            
    	    }
    	   break; 
     }
return 0;
}	

// Prints the element in the array
void printarray(int arraynum[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t", arraynum[i]);
	}
	printf("\n");
}

//Bubble Sort Implemetation
void bubblesort(int array[], int size)
{
	int j, pass;
	//sort the array by comparing the adjacent element and swap the array element if its larger
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
	
}

//Insert Sort Implemetation
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
		}
	}
	return;		
}

//selectionsort Implemetation
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
	return;
}

//shellsort implementation
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
	
    return ;
}

//Quick Sort Implementation
void quicksort(int x[],int first,int last)
{
    int pivot,j,temp,i;

     if(first<last)
     {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
         {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j)
             {
                temp=x[i];
                x[i]=x[j];
                 x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
    
    return ;
}


void partition(int arr[],int low,int high)
{
    int mid;

    if(low<high)
    {
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high)

{

    int i,m,k,l,temp[SIZE];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

void heapsort(int a[],int n) 
{
	int i,t;
	heapify(a,n);
	for (i=n-1;i>0;i--) 
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust(a,i);
	}
}

void heapify(int a[],int n) {
	int k,i,j,item;
	for (k=1;k<n;k++) 
	{
		item = a[k];
		i = k;
		j = (i-1)/2;
		while((i>0)&&(item>a[j])) 
		{
			a[i] = a[j];
			i = j;
			j = (i-1)/2;
		}
		a[i] = item;
	}
}

void adjust(int a[],int n)
{
	int i,j,item;
	j = 0;
	item = a[j];
	i = 2*j+1;
	while(i<=n-1) 
	{
		if(i+1 <= n-1)
		   if(a[i] <a[i+1])
		    i++;
		if(item<a[i]) 
		{
			a[j] = a[i];
			j = i;
			i = 2*j+1;
		} else
		   break;
	}
	a[j] = item;
}

//Swap the data
void swap(int *array1, int *array2)
{
	int tmp;
	tmp = *array1;
	*array1 = *array2;
	*array2 = tmp;
	return;
}

