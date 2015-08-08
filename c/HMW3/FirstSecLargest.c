# include <stdio.h>
int main(void)
{
int number,count,SecondLargest;
int largest=count = 0;
while (count <=10)
{
	printf("enter the number:");
	scanf("%d",&number);
	if(number>largest)
	{
		SecondLargest=largest;
		largest=number;
	}
	count++;
}
printf("The First Largest number of sales is %d\n:",largest);
printf("The Second Largest number of sales is %d\n:",SecondLargest);

}
