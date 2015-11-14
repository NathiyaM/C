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
void display();
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
			display();
		    reverse();
		    display();
		    deletenode();
		}
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
    
    
void display()
{
    ptr=start;
    while(ptr->link!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("NULL\n");
}

void deletenode()
{
    int data[9],i,validdata[9],invaliddata[9];
    printf("Enter the data tobe deleted seperated by spaces");
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
                 invaliddata[i]=0;
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
        
    }
    printf("Invalid Data are\n");
     for(i=0;i<9;i++)
    {
        if(invaliddata[i]==0)
        {
            continue;
        }
        printf("%d\t",invaliddata[i]);
        
    }
    
    printf("The node after deleted is\n");
    display();
}


void deletenode_beg()
{
    ptr=start;
    if(start==NULL)
    {
        printf("Item cannot be find");
    }
    start=ptr->link;
    free(ptr);
    
}

void reverse()
{
    if(start == NULL)
    {
        printf("List is empty");
        return;
    }
    else if(start->link==NULL)
        printf("The numbers are reveresed\n");
    struct node *p1,*p2,*p3;
    p1=start;
    p2=p1->link;
    p3=p2->link;
    p1->link=NULL;
    p2->link=p1;
    while(p3->link!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->link;
        p2->link=p1;
    }
    start=p2;
    printf("List Reversed");

}
