#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXCOLS 80
#define TRUE 1
#define FALSE 0
double eval (char expr [] );
double pop (struct stack *ps);
void push (struct stack *ps, double x);
int empty (struct stack *pq);
int isdigit (char symb);
double oper (int symb, double op1, double op2);

struct stack {
int top;
double items [MAXCOLS];
};

void main ()
{
char expr [MAXCOLS] = {"97+5-"} ;
int position = 0;
/* The class assignment may need to take
care of multi digit input.*/
printf ("%s%s", "the original postfix expression is", expr);
printf ("\n %f", eval (expr) );
return;
}

int isdigit (char symb)
{
return (symb >= '0' && symb <= '9');
}

double eval (char expr [] )
{
int c, position;
double opnd1, opnd2, value;
struct stack opndstk;
opndstk.top = -1;
for (position = 0; (c = expr [position] ) != '\0'; position++)
if (isdigit(c) ) /* is operand */
push (&opndstk, c );
/* it was push (&opndstk, (double (c - '0') ); before */
else /* is operator */
{
opnd2 = pop (&opndstk);
opnd1 = pop (&opndstk);
value = oper (c, opnd1, opnd2);
push (&opndstk, value);
} /* else operator */
return (pop (&opndstk) );
} /* end eval function */

int empty (struct stack *pq)
{
if (pq->front == pq->rear)
return (TRUE);
else
return (FALSE);
} /* end of function empty */

double oper (int symb, double op1, double op2)
{
switch (symb)
{
case '+' : return (op1 + op2);
case '-' : return (op1 - op2);
case '*' : return (op1 * op2);
case '/' : return (op1 / op2);
case '%' : return ( (int) op1 % (int)op2 );
case '^' : return ( pow( op1, op2) );
default : printf ("%s", "illegal operation");
exit (1);
} /* end of switch symb */
} /* end of function oper */


double pop (struct stack *ps)
{
if (empty (ps) )
{
printf ("%s", "stack underflow");
exit (1);
} /* end of empty if */
return (ps->items[ps->top--] );
} /* end of pop function */


void push (struct stack *ps, double x)
{
if (ps->top == MAXCOLS-1)
{
printf ("%s", "stack overflow");
exit (1);
} /* end of if */
else
ps->items[++(ps->top) ] = x;
return;
} /* end of push function */

