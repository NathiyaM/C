#include<stdio.h>
int qualitypoints(int number);
int main()
{
		int point,average=0;
		printf("Enter the student's average:");
		scanf("%d",&average);
		while(average!=-1)
		{
				point=qualitypoints(average);
				printf("%d\n on a 4th point scale is %d\n",average,point);
				printf("Enter the student's average:");
				scanf("%d",&average);
		}
}


int qualitypoints(int number)
{
		int grade;
		if(number>=90)
		{
				grade=4;
				return grade;
		}
		else if(number>=80)	
		{
				grade=3;
				return grade;
		}
		else if(number>=70)
		{
				grade=2;
				return grade;
		}
		else{
				grade=1;
				return grade;
		}
}
