#include<stdio.h>
int main(char argc,char *argv[])
{
char FirstName[30];
char LastName[30];
char String[50];
char MiddleName[10];
int quiz1,quiz2,quiz3,quiz4,mid,midii,final;
FILE *fptr;
if((fptr=fopen("inputfile.txt","r"))==NULL)
{
printf("Error in opening files...");
}
else
{
printf("%-20s%-20s%-20s%7s%7s%7s%7s%7s%7s%7s","FirstName","LastName","MiddleName","quiz1","quiz2","quiz3","quiz4","mid","midii","final\n");
fscanf(fptr,"%s%s%s%d%d%d%d%d%d%d\n",FirstName,LastName,MiddleName,&quiz1,&quiz2,&quiz3,&quiz4,&mid,&midii,&final);
while(!feof(fptr))
{
printf("%-20s%-20s%-20s%7d%7d%7d%7d%7d%7d%7d\n",FirstName,LastName,MiddleName,quiz1,quiz2,quiz3,quiz4,mid,midii,final);
fscanf(fptr,"%s%s%s%d%d%d%d%d%d%d\n",FirstName,LastName,MiddleName,&quiz1,&quiz2,&quiz3,&quiz4,&mid,&midii,&final);
 } 
fclose(fptr);
}
return 0;
}

