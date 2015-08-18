#include<stdio.h>
int main()
{
	int row,column,total=0,no;
	int array1[3][5]={{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
	for(row=0;row<3;row++)
	{
		for(column=0;column<5;column++)
		{	
			total+=array1[row][column];
			printf("%d\n",total);
		}
		
	}
printf("%d\ntotal is",total);
}

