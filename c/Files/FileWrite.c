#include<stdio.h>
int main()
{
char name[30];
int studentid;
int marks;
FILE *fptr;
if((fptr=fopen("stdout.dat","w"))==NULL)
{
printf("Error in opening files...");
}
else
{
printf("Enter the studentid,name,marks\n");
printf("Enter the Eof\n");
printf("?");
scanf("%d%s%d\n",&studentid,name,&marks);
while(!feof(stdin))
{
fprintf(fptr, "%d %s %d\n", studentid, name,marks);
printf( "? " );
scanf( "%d%s%d", &studentid, name, &marks);
 } 
fclose(fptr);
}
return 0;
}

