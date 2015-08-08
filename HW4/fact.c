#include<stdio.h>
int main()
{
int i,fact=1;
printf("x\tfactorial of x\t\n");
for(i=1;i<=5;i++)
{
	fact=fact*i;
	printf("%d\t%d\t\n",i,fact);
}	
return 0;
}
