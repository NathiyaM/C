#include<stdio.h>
int main()
{
char instructor[7]="bineet"; 
char *pinstructor="bimal"; 
int myArray[100] = {2, 3, 5}; 

printf("%d", myArray[5]);
printf("%c, %c", instructor[2], *(pinstructor+2));
}
 
