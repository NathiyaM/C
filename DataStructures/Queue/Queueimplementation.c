/*****************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension,Santa Cruz                     	*/
/*                                                                              */
/*                                                                              */
/* 			Advanced C Programming                                                	*/
/*                                                                              */
/* 			Instructor :Rajainder A.Yeldandi							                      		*/
/*                                                                              */
/* 			Author:Nathiya Meganathan										                          	*/
/*																			                                      	*/
/*			Assignment No:9													                              	*/
/*																			                                      	*/
/*			Topic:Queues													                                	*/
/*																			                                      	*/
/*			FileName:QueueEnqueDeque.c										                        	*/
/*			Date of the Program:11.20.2015									                      	*/
/*			Objective: Implement the Queue DataStructure using an array.Read        */
/*			the choice and data input from a file.Perform Enque or Dequq 	        	*/
/*			operations depending on the choice of the input preceding the 		      */
/*			data element.Print the inserted and removed data from the queue		      */
/*			when the choice isto perform Enqueu,you will read the choice		        */
/*			and data.But when the choice isto perform Deque,there is no data	      */
/*          to be read.															                            */
/********************************************************************************/  
/* Preprocessor Directives */

#include <stdio.h>
#include<stdlib.h>
#define MAX 50
//Queue Declaration
int queue_array[MAX];
int rear = - 1;
int front = - 1;
//function prototype
void insert(int add_item);
void delete();
void display();

int main(int argc,	char *argv[])
{
    int data;
    char choice;
    FILE *iptr;
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
						printf("The input read from the file is%c\n",choice);
						insert(data);//function calling
            display();
						break;
					}
					case 'D':
					{
					    printf("The input read from the file is%c\n",choice);
						  delete();
              display();
						break;
					}
            
				}
			}
		fclose (iptr);
		}
      
	}	
return 0;
}
    
/*while inserting the element increment the rear end and insert the element at the last*/
void insert(int add_item)
{
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /*End of insert()*/
 
/*Delete the first element from the queue and increment the front variable,before
deleting check whether the queue is empty or not"*/
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /*End of delete() */

/*Display the contents of the queue element */
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} /*End of display() */
