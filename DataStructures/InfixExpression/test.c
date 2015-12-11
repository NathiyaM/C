#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc,char *argv[2])
{
    FILE *iptr;
    char *str[3];
    if(argc!=2)
    {
        printf("Invalid Input:Program Name,Input to the File");
    }
    else
    {
        if((iptr=fopen(argv[1],"r"))==NULL)
        {
            printf("error in opening the file\n");
        }
        else
        {
            while(!feof(iptr))
            {
                fscanf (iptr,"%s", &str);
                printf("%s\t",*str);
            }
            fclose(iptr);
        }
    }
    return 0;
}