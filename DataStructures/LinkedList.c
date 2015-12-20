/*****************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension,Santa Cruz                     	*/
/*                                                                              */
/*                                                                              */
/* 			Advanced C Programming                                              */
/*                                                                              */
/* 			Instructor :Rajainder A.Yeldandi							        */
/*                                                                              */
/* 			Author:Nathiya Meganathan										    */
/*								            	 									                                      	*/
/*			Assignment No:		11      									    */
/*																			                                      	*/
/*			Topic:LinkedList									                */
/*	    								                                      	*/
/*			FileName:LinkedList.c							               		*/
/*			Date of the Program:12.2.2015										*/
/*			Objective: Read the input from the input file
            not initialized an array with input numbers.
            Create and add the link to the list as  read the input. 
            Prompt the user for deleting the entries from the list and 
            output after each deletion.          							    						                            */
/********************************************************************************/  
//Predefined directives.


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *link;
}node;

node* createnode(int data);
void insertnode(int data);
void deletenode();
void displaynode();
void display_after_reverse();
void reverse();
node *start=NULL;
node *temp,*ptr;
void deletenode_beg();

 int main(int argc,char *argv[])
 {
     FILE *iptr;
     int data;
     if (argc!=2)
	{
		printf ("usage:program name, Input File\n");
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
				fscanf (iptr,"%d", &data);
				insertnode(data);
			}
			fclose(iptr);
		}
    printf("The original linked list after node gets inserted is \n");
		displaynode();
    printf("The list after reversed is \n");
		reverse();
		deletenode();
	}
	return 0;
 }
 

node* createnode(int data)
{
    
    temp=(node*)malloc(sizeof(node*));
    if(temp==NULL)
    {
        printf("Insufficent Memory\n");
        exit(0);
    }
    temp->data=data;
    temp->link=NULL;
  //  printf("The starting node got created\n");
    return temp;
}



void insertnode(int data)
{
    node *tempnode;
    ptr=start;
    temp=createnode(data);
    if(ptr==NULL)
    {
        start=temp;
    }
    else 
    {
        while(1)
        {
            if(ptr->link!=NULL)
                ptr=ptr->link;
            else
                break;
        }
        ptr->link=temp;
    }
}
    
void displaynode()
{
    ptr=start;
    while(ptr->link!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("NULL\n");
}
    
void display_after_reverse()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("NULL\n");
}


void deletenode()
{
    int data[9],i,validdata[9],invaliddata[9];
    printf("Enter the data tobe deleted seperated by spaces one at a time");
    for(i=0;i<9;i++)
    {
        scanf("%d",&data[i]);
        node *preptr;
        preptr=start;
        ptr=preptr->link;
         /* if(ptr->data==data)
        {
        deletenode_beg();
         }*/
        while(ptr!=NULL)
        {
            if(ptr->data==data[i])
             {
                 preptr->link=ptr->link;
                 free(ptr);
                 validdata[i]=data[i];
                 invaliddata[i]=-1;
                 break;
            }
            else
            {
                invaliddata[i]=data[i];
                validdata[i]=0;
                
             }
            ptr=ptr->link;
            preptr=preptr->link;
         }
    }
    printf("Valid Data's are\n");
    for(i=0;i<9;i++)
    {
        if(validdata[i]==0)
        {
            continue;
        }
        printf("%d\t",validdata[i]);
        printf("\n");
        
    }
    printf("Invalid Data are\n");
     for(i=0;i<9;i++)
    {
        if(invaliddata[i]==-1)
        {
            continue;
        } 
        printf("%d\t",invaliddata[i]);
        printf("\n");
        
    }
    
    printf("The node after deleted is\n");
    display_after_reverse();
}

// reverse the list.
void reverse()
{
    struct node *p, *q, *r;
    p = q = r = start;
    p = p->link->link;
    q = q->link;
    r->link = NULL;
    q->link = r;
    while (p->link!= NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    start = q;
    display_after_reverse();
}
