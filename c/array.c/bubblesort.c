#include<stdio.h>
#define size 10
void bubblesort(int *b);
int main()
{
	int i, a[size]={1,2,3,4,5,10,9,8,7,6};
	printf("List Before ascending order is:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	bubblesort(a);
	printf("List after ascending order is:\n");
	
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}

	return 0;
}

void bubblesort(int *b)
{
	int tmp,i,j;
	for (i=0;i<size;i++)
		for(j=0;j<size;j++)
		{	
			if (b[j]>b[j+1])
			{
				tmp=b[i];
				b[i]=b[i+1];
				b[i+1]=tmp;
			}
	}	printf("%d\t",b[i]);
}
 

