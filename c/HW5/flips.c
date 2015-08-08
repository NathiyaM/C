#include<stdio.h>
int flip();
int main()
{
		int no, HeadCount=0,TailCount=0;
		no=flip();
		printf("%d",no);
       while(no>=1)
		{
				if(no==0)
				{
						printf("Head");
 						HeadCount=HeadCount+1;
				}
				else
				{
						printf("Tail");
						TailCount=TailCount+1;
				}
		}
		printf("%d The Head Counts are:",HeadCount);
		printf("%d The tail Counts are:",TailCount);
}


int flip()
{
		int f,number,i;
	    printf("enter the number of times the coins to be flipped");
	  	scanf("%d",&number);	
		for(i=0;i<number;i++)			
		{
			f=rand()%2;
			return f;
		}
f=2;
}
