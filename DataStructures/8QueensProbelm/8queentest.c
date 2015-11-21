#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define BOARDSIZE 8
#define DIAGONAL (2 * BOARDSIZE - 1)
#define DOWNOFFSET 7
#define FALSE 0
#define TRUE 1
void writeBoard (void);
void clearBoard (void);
void addQueen (void);
int queencol [BOARDSIZE]; /* queen column */
bool colfree [BOARDSIZE]; // is column free
bool upfree [DIAGONAL ]; // up diagonal free
bool downfree [DIAGONAL ]; //down diagonal free
int queencount = -1; // row queen is placed
int numsol = 0; // number of solutions found
int main (void)
{
int i;
for (i = 0; i < BOARDSIZE; i++)
{
clearBoard ();
queencol[++queencount] = i;
colfree[i] = FALSE;
upfree[queencount + i] = FALSE;
downfree [queencount - i +
DOWNOFFSET] = FALSE;
addQueen ();
} /* end of for loop */
return 0;
} /* end of main function */
void addQueen (void)
{
int col; /* column being tried for the queen */
queencount++;
for (col = 0; col < BOARDSIZE; col++)
{
if (colfree [col] && upfree [queencount + col]&& downfree [queencount - col +DOWNOFFSET ] )
{ // put the queen in position (queencount, col)
queencol [queencount] = col;
colfree [col] = FALSE;
upfree [queencount + col] = FALSE;
downfree [queencount - col +DOWNOFFSET] = FALSE;
if (queencount == BOARDSIZE - 1)
{ /* terminal condition */
printf ("\n %d Queen Solution: %d \n\n", 8, ++numsol);
writeBoard ();
}
else
addQueen (); /* recursive call */
if (queencount - 1 < 0)
continue;
colfree [col] = TRUE; // backtrack queen
upfree[queencount - 1 + col] = TRUE;
downfree [queencount - 1 - col + DOWNOFFSET] = TRUE;
queencount--;
} /* end of if colfree */
} /* end of for loop */
} /* end of function addQueen */


void writeBoard (void) /* prints the output of N
queens placement */
{
int col;
static int qcount = 0;
for (col = 0; col < BOARDSIZE; col++)
{
if (queencol [qcount] == col)
printf ("Q ");
else
printf ("* ");
} /* end of for loop */
printf ("\n\n");
if (qcount++ < BOARDSIZE - 1)
writeBoard ();
qcount = 0;
} /* end of writeBoard function */
/* clears the board for next placement */


void clearBoard (void)
{
    int i,j;
for (i = 0; i < BOARDSIZE; i++)
{
colfree [i] = TRUE;
queencol [i] = -1;
} /* end of for loop */
for (j = 0; j < DIAGONAL; j++)
{
upfree [j] = TRUE;
downfree [j] = TRUE;
} /* end of for loop */
queencount = -1;
} /* end of clearBoard function */

