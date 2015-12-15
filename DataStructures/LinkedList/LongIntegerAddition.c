#include<stdio.h>
#include<stdlib.h>
struct list1
{
    int data;
    struct node *prev;
    struct node *next;
};

struct list2
{
    int data;
    struct node *prev;
    struct node *next;
};

struct list1 *head;
struct list2 *head;
void insertnode(int data);
void reverse();
void print();

int main(int argc,char argv[])
{
	int data;
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
				insertnodelist1(data);
			}
			fclose(iptr);
		}
		if ( (iptr = fopen (argv[2],"r")) == NULL)
        {
        	printf("Error in opening files...");
        }
		else
		{
			while(!feof(iptr))
			{
				fscanf (iptr,"%d", &data);
				insertnodelist2(data);
			}
			fclose(iptr);
		}
		
	}
	return 0;
 }
 
 struct list1* getnode(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
	
}

struct list2* getnode(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insertnodelist1(int data)
{
    struct list1 *newnode = getnode(data);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void insertnodelist2(int data)
{
    struct list2 *newnode = getnode(data);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void printlist1()
{
    struct list1 *temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printlist2()
{
    struct list2 *temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}



 
 
 
