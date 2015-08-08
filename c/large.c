# include <stdio.h>
int main(void)
{
int a,b;
printf("enter the two numbers:");
scanf("%d%d",&a,&b);
if(a==b)
{
	printf(" The numbers are equal\n");
}
if(a>b)
{
	printf("%d is larger than %d\n",a,b);
}
if(a<b)
{
	printf("%d is lesser than %d\n",a,b);
}
}
