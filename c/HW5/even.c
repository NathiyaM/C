#include<stdio.h>
int even(int no);
int main()
{
int r,number;
printf("enter the integer:");
scanf("%d",&number);
while(number!=-1)
{
r=even(number);
if(r==0)
	{
	printf("%dis a even integer\n",number);
}
else
{	
printf("%dis not a even integr\n",number);
}
printf("enter the integer:");
scanf("%d",&number);
}
return 0;
}

//function definition

int even(int no)
{
int remainder;
return no%2;
}

