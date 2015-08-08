# include <stdio.h>
int main()
{
int a;
printf("Enter the Five Digit number:");
scanf("%d",&a);
printf("%d   %d   %d   %d   %d\n",a%5,(a%3)+1,a%3,a%4,a%10);
}




