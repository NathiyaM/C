#include<stdio.h>
struct clientdata{
int accnumber;
char lastname[15];
char firstname[15];
double balance;
};
int main(void)
{
	FILE *cfptr;
	int i;
	struct clientdata client ={0,"","",0.0};
	if((cfptr=fopen("credit.txt","wb+"))==NULL)
	{
		printf("The file cannot be opened");
	}
	else
	{
		for(i=1;i<=100;i++)
		{
			fwrite(&client,sizeof(struct clientdata),1,cfptr);
		}
    fclose(cfptr);
}
return 0;
}


