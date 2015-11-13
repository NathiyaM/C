#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

#define ISEMPTY printf("\nEMPTY LIST:");
/*
 * Node Declaration
 */
struct node
{
    int value;
    struct node *next;
};
 typedef struct node snode;
 snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;
snode* create_node(int val);
void insert_node(int val);
void display();
 void reverse(snode *ptr);


 
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
				insert_node(data);
			}
			fclose(iptr);
			display();
			reverse(first);
		}
	}
	return 0;
 }
 
 
 /*
 * Creating Node
 */
snode* create_node(int val)
{
    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}

 void insert_node(int val)
{
    
    newnode = create_node(val);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
}    
 
 
 void display()
{
    if (first == NULL)
    {
        ISEMPTY;
        printf(":No nodes in the list to display\n");
    }
    else
    {
        printf("The LinkedList in Original Order is \n");
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {    
            printf("%d\t", ptr->value);
        }
    }
}

    /*
 * Display non-empty list in Reverse Order
 */
void reverse(snode *ptr)
{
    int val;
 
    if (ptr == NULL)
    {
        ISEMPTY;
        printf(":No nodes to display\n");
    }
    else
    {
        if (ptr != NULL)
        {
            val = ptr->value;
            reverse(ptr->next);
            printf("%d\t", val);        
        }
 
    }
}