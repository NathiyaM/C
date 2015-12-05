#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    FILE *iptr;
    int data;
    if (argc!=2)
	{
		printf ("usage:program name, Input File\n");
		exit (1);
	} 
	/*Start Opening and reading the char from the file one by one,if can't open
	  the file,raise the exception*/
	else
	{
		if ( (iptr = fopen (argv[1],"r")) == NULL)
        {
        	printf("Error in opening files...");
        }
		else
		{
			while(!feof(iptr))
			{
				fscanf (iptr,"%d", &data);
				printf("%d\t",data);
			}
		
			fclose(iptr);
		}
	}
	return 0;
}