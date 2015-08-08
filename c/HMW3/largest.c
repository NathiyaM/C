# include <stdio.h>
int main(void)
{
int number,count;
int largest=count = 0;
while (count <=10)
{
	printf("enter the number:");
	scanf("%d",&number);
	if(number>largest)
	{
		largest=number;
	}
	count++;
}
printf("The Largest number of sales is %d\n:",largest);
}
