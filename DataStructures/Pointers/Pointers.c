/********************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension,Santa Cruz                   	*/
/*                                                                              */
/*                                                                              */
/* 			Advanced C Programming                                           	*/
/*                                                                              */
/* 			Instructor :Rajainder A.Yeldandi									*/
/*                                                                              */
/* 			Author:Nathiya Meganathan											*/
/*																				*/
/*			Assignment No:5														*/
/*																				*/
/*			Topic:Pointers														*/
/*																				*/
/*			FileName:Pointers.c													*/
/*																				*/
/*			Date of the Program:10.24.2015										*/
/*																				*/	
/*			Objective:The pointers, the value at their address,					*/ 
/*			declaration of different pointers and their dereferencing			*/
/********************************************************************************/  

/* Preprocessor Directives */

#include<stdio.h>
int main()
{
	int i, a=25,*aptr;/* aptr is a pointer to an integer */
	float b=3.142,*bptr;/* bptr is a pointer to an float */
	double c=1.73217,*cptr;/* cptr is a pointer to an double */
	char str[]="Hello,C Programmer",*strptr;
	char d='X',*dptr;
	aptr=&a; /* aptr set to address of a */
	bptr=&b; /* bptr set to address of b */
	cptr=&c; /* cptr set to address of c */
	strptr=str; /* strptr set to address of first element in the string */
	dptr=&d; /* dptr set to address of d */
	/* Print the Value of the variables,address of the variables,and address of the pointers */
	printf("The value of the variables\t\tAddress of the variables \t\t Address of the Pointers\n");
	printf("\t%d\t\t\t\t%p\t\t\t\t%p\t\n",a,&a,aptr);
	printf("\t%.3f\t\t\t\t%p\t\t\t\t%p\t\n",b,&b,bptr);
	printf("\t%.5f\t\t\t\t%p\t\t\t\t%p\t\n",c,&c,cptr);
	printf("\t%c\t\t\t\t%p\t\t\t\t%p\t\n",d,&d,dptr);
	printf("\t%s\t\t\t%p\t\t\t%p\t\n",str,str,strptr);
	/* Print the value after dereferencing the pointers */
	printf("The values after dereferencing the pointers is \n");
	printf("\t%c\t%.5f\t%.3f\t%d\t",*dptr,*cptr,*bptr,*aptr);
	for(;*strptr!='\0';strptr++)
	{
		printf("%c",*strptr);
	}
	printf("\n");
	
	return 0;
}



