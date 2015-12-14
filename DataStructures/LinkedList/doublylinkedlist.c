#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;
void insertathead(int data);
void insertattail(int data);
void reverse();
void print();
int main()
{
    int data,choice=0;
    head=NULL;
   // while(choice==0)
  //  {
    //printf("Enter the data to insert\n");
    //scanf("%d",&data);
    insertathead(2);
    print();
    reverse();
    insertathead(3);
    print();
    reverse();
    insertathead(4);
    print();
    reverse();
    //printf("Do you want to contiue 0|1\n");
  //  scanf("%d",&choice);
    printf("\n");
    //}
    return 0;
}

struct node* getnode(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insertathead(int data)
{
    struct node *newnode = getnode(data);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void insertattail(int data)
{
    struct node *newnode = getnode(data);
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
}

void reverse()
{
    struct node *temp = head;
    if(temp==NULL)
        return;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    //traversing backward using prev
    printf("REVERSE:");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void print()
{
    struct node *temp = head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
