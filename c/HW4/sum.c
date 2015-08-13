#include<stdio.h>
int main()
{
int i,sum,number;
sum=0;
for(i=0;i<5;i++)
{
printf("enter the number one at a time:");
scanf("%d",&number);
sum=sum+number;
}
printf("The sum of Five Number is%d",sum);
return 0;
}

