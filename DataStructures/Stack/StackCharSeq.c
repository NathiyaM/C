#include<stdio.h>
#include<stdlib.h>
#define MAXSTACK 26
#define EMPTYSTACK -1
#define TRUE 1
#define FALSE 0
/* function prototypes (signatures) */
int empty (struct CHSTACK *);
char pop (struct CHSTACK *);
void push (struct CHSTACK  *, char);
/* global declarations */
typedef struct{
int top;
char stackelement [MAXSTACK];
} CHSTACK;

/* start of main program logic */
int main()
{
CHSTACK alphstack, *asp;
char seq, ch, keystroke;
int i;
alphstack.top = EMPTYSTACK;
asp = &alphstack;
/* fill up the stack with input from the user */
for (i = 0; i < MAXSTACK; i++)
{
printf ("\n Please enter the next char in seq");
scanf ("%c%c", &seq, &keystroke);
push (asp, seq);
} /* end of first for loop */

/* empty the stack and print values */
for (i = 0; i < MAXSTACK; i++)
{
ch = pop (asp);
printf ("\n next char in seq is: %c", ch);
}
printf ("\n\n End of character seq **\n");
return 0;
} /* end of main routine */

/* function verifies whether stack is empty */
int empty (CHSTACK *ps)
{
if (ps->top == -1)
return (TRUE);
else
return (FALSE);
} /* end of empty function */
char pop (CHSTACK *ps)
{
if (empty (ps) )
{
printf ("%s","stack underflow");
exit (1);
} /* end of empty if */
return (ps-> stackelement[ps->top--] );
}
