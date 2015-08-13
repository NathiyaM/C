#include<stdio.h>
int main()
{
int i,number,no;
int small=0;
printf("enter the no of integers to find the smallest:");
scanf("%d",&no);
for(i=0;i<no;i++)
{
	printf("enter the number one at a time:");
	scanf("%d",&number);
	if(small==0)
	{
	small=number;
	printf("hello");
	}
	else if (number<small)
	{
	small=number;
	}
}
printf("The smallest of %d Numbers is%d\n",no,small);
return 0;
}
