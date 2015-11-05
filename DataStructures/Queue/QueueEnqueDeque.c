/*****************************************************************************/
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
/*			Assignment No:9														*/
/*																				*/
/*			Topic:Queues														*/
/*																				*/
/*			FileName:QueueEnqueDeque.c											*/
/*			Date of the Program:11.02.2015										*/
/*			Objective: Implement the Queue DataStructure using an array.Read    */
/*			the choice and data input from a file.Perform Enque or Dequq 		*/
/*			operations depending on the choice of the input preceding the 		*/
/*			data element.Print the inserted and removed data from the queue		*/
/*			when the choice isto perform Enqueu,you will read the choice		*/
/*			and data.But when the choice isto perform Deque,there is no data	*/
/*          to be read.															*/
/********************************************************************************/  

/* Preprocessor Directives */

#include<stdio.h>
#include<stdlib.h>
/*Declare the max size of the array */
#define MAXSIZE 30
/*Queue Declaration */
struct queue
{
	int	front,rear;
	char queueelement[MAXSIZE];
};
/* function protoype for push,pop,Empty */
void Enqueue(struct queue *ps,int data);
int Dequeue(struct queue *ps);
int EmptyQueue(struct queue *ps);
/*Main Program DEclaration */
int main(int argc,	char *argv[])
{
	/*Decalration of File pointer for opening and reading the characters from the file */
	FILE *iptr;
	/* Structure Variable Declaration */
	struct queue Q, *q;
	//Intializing the Queue 
	Q.front = Q.rear= -1;
	char choice;
	int i,data,p_num;
	q = &Q;
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
			while(!feof(iptr))
			{
				fscanf (iptr,"%c", &choice);
				//if input read from the file E,push the content onto the Queue.if D then Dequeue the item
				 
				switch(choice)
				{
					case 'E':
					{
						fscanf(iptr,"%d",&data);
						Enqueue(q,data);//function calling
						break;
					}
					case 'D':
					{
						p_num=Dequeue(q);
						printf("poped item is%d\n",p_num);
						break;
					} 
					
				}
			}
		fclose (iptr);
				
		}
	}	
return 0;
}

/*Function Definiton for enqueue operation */
void Enqueue(struct queue *ps,int data)
{
	if(ps->rear==MAXSIZE-1)
		ps->rear=0;
	else
		(ps->rear)++;
	//Check for overflow
	if(ps->rear==ps->front)
	{
		printf("The Item cannot be pushed onto the stack\n");
		exit(1);
	}
	else
	{
		ps->queueelement[ps->rear]=data;
		printf("The Item Pushed on to the stack is %d\n",data);
	}
	return;
}

/*Function Definition for Dequeue operation */
int Dequeue(struct queue *ps)
{
	if(EmptyQueue(ps))
	{
		printf("The Queue is Empty\n,Going to exit");
		exit(1);
	}
	if(ps->front==MAXSIZE-1)
		ps->front=0;
	else
		(ps->front)++;
		return (ps->queueelement[ps->front]);
	
}
/*Check whether the queue is empty or not */
int EmptyQueue(struct queue *ps)
{
	if(ps->front==ps->rear)
	  return 1;
	else
		return 0;
}
 
	
