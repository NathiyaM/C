#include<stdio.h>
int reverse(int number);
int main()
{
int no,n;
printf("Enter the number to be reveres:");
scanf("%d",&no);
n=reverse(no);
printf("The Reverse of the given number is:%d",n);
}

int reverse(int number)
{
int r=0;
while(number!=0)
{
r=r*10;
r=r+number%10;
number=number/10;
}
return r;
}
