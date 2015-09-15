#include <stdio.h>
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Too many arguments");
		exit(1);
	}
	else
	{
		printf("The argument supplied is %s%s\n",argv[0],argv[1],argv[2]);
	}
		printf("The argument supplied is %s%s\n",argv[0],argv[1],argv[2]);
	
}

