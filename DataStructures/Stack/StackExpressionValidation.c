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
/*			Assignment No:8														*/
/*																				*/
/*			Topic:Stacks														*/
/*																				*/
/*			FileName:StackExpressionValidation.c								*/
/*			Date of the Program:11.01.2015										*/
/*			Objective: Evaulate the validity of the scopes in the expression    */
/*			implementing the stacks.Ignore the operators and operand in the 	*/
/*			expression while checking the validity of the expression.			*/
/*			print each symbol encountered while scanning the expression and the */
/*			matching the result.												*/
/*			Read all the symbols from the input file and write into the output	*/
/*          file.																*/
/********************************************************************************/  

/* Preprocessor Directives */

#include<stdio.h>
#include<stdlib.h>
/*Declare the max size of the array */
#define MAXSIZE 30
#define TRUE 1
#define FALSE 0
/*Stack Declaration */
struct stack
{
	int	top;
	char stackelement[MAXSIZE];
};
/* finction protoype for push,pop,Empty */
void push(struct stack *ps,char expression);
char pop(struct stack *ps);
int EmptyStack(struct stack *ps);
/*Main Program DEclaration */
int main(int argc,	char *argv[])
{
	/*DEcalration of File pointer for opening and reading the characters from the file */
	FILE *iptr;
	/* Structure Variable Declaration */
	struct stack expression, *expr;
	//Intializing the Stack 
	expression.top = -1;
	char expres,c;
	int i;
	expr = &expression;
	/*Checking the commandline arguments*/
	if (argc!=2)
	{
		printf ("usage:program name, Input File, Output File\n");
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
			for (i = 0;i < 62;i++)
			{
				fscanf (iptr,"%c", &expres);
				/*if encounters any one the braces,start pushing the braces into
				  the stack */
				if((expres=='{') || (expres=='(') || (expres=='['))
				
					push(expr, expres);//function calling
				/*if encounters any one of the braces,start poping the element ,
				  then compare the poped opening element with the closing braces,if it matches continue,
				  else,expression is invalid and exit */
				else if((expres=='}')||(expres==')')||(expres==']'))
				{
						c=pop(expr);
						if(((c=='{')&&(expres=='}')) ||((c=='[')&&(expres==']')) || ((c=='(')&&(expres==')')))
							printf("poped item is%c\n",c);
						else
							printf("Invalid Expression\n");
				} 
				/* ignore the operator and	operand */	
				else
					printf("The operators or operands are ignored %c\n",expres);
					continue;
			}
			/* Finally after all the char are read,push and pop operation are over,
			  check whether the stack empty or not ,if empty expression valid else invalid */
			if(EmptyStack(expr))
				printf("The Expression is Valid\n");
			else
				printf("The Expression is Invalid\n");
			
		}
		fclose (iptr);
				
		}
	
return 0;
}

/*Function Definiton for push operation */
void push(struct stack *ps,char expression)
{
	if(ps->top==MAXSIZE-1)
	{
		printf("We can push anymore into the stack\n Going to Exit..\n");
		exit(0);
	}
	else
	{
		ps->stackelement[++(ps->top)]=expression;
		printf("The Item Pushed on to the stack is %c\n",expression);
	}
	return;
}

/*Function Definition for pop operation */
char pop(struct stack *ps)
{
	if(EmptyStack(ps))
	{
		printf("The Expression is Invalid\n,Going to exit");
		exit(1);
	}
	else
	{
		return ps->stackelement[(ps->top)--];
	}
}
/*Check whether the stack is empty or not */
int EmptyStack(struct stack *ps)
{
	if(ps->top==-1)
	  return 1;
	else
		return 0;
}
 
	
