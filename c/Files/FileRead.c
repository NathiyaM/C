#include<stdio.h>
int main()
{
char name[30];
int studentid;
int marks;
FILE *fptr;
if((fptr=fopen("input.txt","r"))==NULL)
{
printf("Error in opening files...");
}
else
{
printf("%14d%15s%7d","STUDENTID","NAME","MARKS");
fscanf(fptr,"%d%s%d\n",&studentid,name,&marks);
while(!feof(fptr))
{
printf("%14d %15s %7d\n", studentid, name,marks);
fscanf( fptr,"%d%s%d", &studentid, name, &marks);
 } 
fclose(fptr);
}
return 0;
}

