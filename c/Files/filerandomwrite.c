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
	struct clientdata client ={0,"","",0.0};
	if((cfptr=fopen("credit.txt","rb+"))==NULL)
	{
		printf("The file cannot be opened");
	}
	else
	{
		printf("enter the account number""(1to100,0 to end output)\n");
		scanf("%d",&client.accnumber);
		while(client.accnumber!=0)
		{
			printf( "Enter lastname, firstname, balance\n? " );
			fscanf( stdin, "%s%s%lf", client.lastname,client.firstname, &client.balance );
			fseek( cfptr, ( client.accnumber - 1 ) * sizeof( struct clientdata ), SEEK_SET );
			fwrite(&client,sizeof(struct clientdata),1,cfptr);
			printf("enter the account number");
			scanf("%d",&client.accnumber);
		}
    fclose(cfptr);
}
return 0;
}


