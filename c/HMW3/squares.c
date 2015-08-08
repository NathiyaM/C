# include <stdio.h>
int main()
{
int sides,i,j;
i=j=0;
printf("enter the sides of the squares:");
scanf("%d",&sides);
while(i<=sides)
{	
	while(j<sides)
	{
		printf(" * ");
		j++;
	}
printf("\n");
i++;	
j=0;
}
}

