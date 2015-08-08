#include<stdio.h>
void prime(int number);
int main()
{
	int no;
	no = 1000;
	printf("the prime numbers from 1 to 1000 is \n");
	prime( no);
}

void prime(int number)
{
	int i;
	for(i=2;i<=number;i++)
		{
				if (i%2!=0)
				{
						printf("%d\t",i);
				}
		}
}
