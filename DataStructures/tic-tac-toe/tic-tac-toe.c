/********************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension, Santa Cruz                   	*/
/*                                                                              */
/*                                                                              */
/* 			Advanced C Programming                                           	*/
/*                                                                              */
/* 			Instructor :Rajainder A.Yeldandi									*/
/*                                                                              */
/* 			Author:Nathiya Meganathan											*/
/*																				*/
/*			Assignment No:6														*/
/*																				*/
/*			Topic:Tic Tac Toe													*/
/*																				*/
/*			FileName:tic-tac-toe.c												*/
/*			Date of the Program:10.30.2015										*/
/*			Objective:Implement the game Tic Tac Toe as described below.show 	*/
/*			the input and output of the game and finally the result.			*/
/*			show the initial board, the moves of each player, and the result of */
/*			the game including the final board									*/
/********************************************************************************/  

/* Preprocessor Directives */
#include<stdio.h>
#include<stdlib.h>
char board[4][4];//Variable declaration for board
// function prototypes
void initboard(void);
void printboard(void);
void player1_move(void);
void player2_move(void);
char check(void);
char isBoardFull(void);
//main function
int main()
{
	/* variable declaration */
	char done=' ';
	printf("WELCOME TO TIC-TAC-TOE GAME\n");
	printf("PLAYER1 plays against another PLAYER2\n");
	/*calling function for intializing the board with empty cells*/
	initboard();
	do
	{
		//print the board
		printboard();
		player1_move();//call player1 move function to place the cell for player1
		done=check();//check whether the player1 wins or not,if it wins,exit from the loop
		if(done!=' ')
			break;
		printboard();
		/* check whether the board is full or not continue to the move for player2 and check whether the 
		player 2 wins after their move and check whether the board is full or not*/
		done=isBoardFull();
		if(done!=' ')
			break;
		player2_move();
		done=check();
		if(done!=' ')
			break;
		done=isBoardFull();
		if(done!=' ')
			break;
	}while(done==' ');
	/*check for return statement from the loop,to declare the win*/
	if(done=='X')
		{printf("Congrats, Player1 Wins\n");
		printboard();}
	else if(done=='0')
		{printf("Congrats, Player2  Wins\n");
		printboard();}
	else
		printf("Match Draw\n");
return 0;
}
/*function definitions for initializing the board
by declaring the two dimensional array*/
void initboard(void)
{
	//variable declaration 
	int i, j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			board[i][j]=' ';
		}
	}
}
/*function definition for printing the board,after each move from
each players,display after he wins*/
void printboard(void)
{
	int t;
	for(t=0;t<4;t++)
	{
			printf(" %c | %c | %c | %c ", board[t][0],board[t][1],board[t][2],board[t][3]);
			if (t!=3)
				printf("\n---|---|---|---\n");
		}
			printf("\n");


}
/*function definition for player 1 move,check the enter the
cells is valid to place,if it so place it else print invalid move,
ask players to enter the cell again*/
void player1_move(void)
{
	int x,y;
	printf("Hi Player1,Enter the X and Y coordinates start from (1to4)");
	scanf("%d%d", &x, &y);
	x--;
	y--;
	if(board[x][y]!= ' ')
	{
    printf("Invalid move, try again.\n");
    player1_move();
 	 }
  	else board[x][y] = 'X';
}
/*function definition for player 1 move,check the enter the
cells is valid to place,if it so place it else print invalid move,
ask players to enter the cell again*/

void player2_move(void)
{
	int x,y;
    printf("Hi Player2 Enter the X and Y coordinates start from (1 to 4)");
    scanf("%d%d", &x, &y);
    x--;
	y--;
	if(board[x][y]!= ' ')
	{
    printf("Invalid move, try again.\n");
    player2_move();
     }
    else board[x][y] = '0';
}

/* See if there is a winner. */
char check(void)
{
  int i;

  for(i=0; i<4; i++)  /* check rows */
    if(board[i][0]==board[i][1] &&
       board[i][0]==board[i][2] && board[i][0]==board[i][3]) return board[i][0];

  for(i=0; i<4; i++)  /* check columns */
    if(board[0][i]==board[1][i] &&
       board[0][i]==board[2][i] && board[0][i]==board[3][i]) return board[0][i];

  /* test diagonals */
  if(board[0][0]==board[1][1] &&
     board[1][1]==board[2][2] && board[3][3]==board[3][3])
       return board[0][0];

  if(board[0][3]==board[1][2] &&
     board[1][2]==board[2][1] && board[2][1]==board[3][0])
       return board[0][3];

  return ' ';
}
/* check to see whether the board is full or not,
exit from the looop if any of the cell is empty or
continue to check all the cells.returns Full 'F' */

char isBoardFull(void)
{
	int i,j;
	char full=' ';
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(board[i][j]==' ')
			{
				return ' ';
				break;
			}
		}
	}
	return 'F';
}
