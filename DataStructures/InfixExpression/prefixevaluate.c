#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE_CHARS 40

typedef short boolean;
typedef char StackEntry; 


typedef struct node_s{
StackEntry entry;
struct node_s *next;
}node_t;

typedef struct{
node_t *top;
}Stack;

void InitializeStack(Stack *s);
node_t *MakeNode(StackEntry item);
void Push(StackEntry item, Stack *s);
boolean StackEmpty(Stack *s);
StackEntry Pop(Stack *s) ;
StackEntry StackTop(Stack *s);

StackEntry nextInput();
int getPriority(char ch);
void reverse_string(StackEntry str[]);
void InfixToPrefix(Stack *myStack,StackEntry str1[],StackEntry str2[]);


int 
main()
{
Stack mysatck;
StackEntry str1[MAX_SIZE_CHARS],str2[MAX_SIZE_CHARS];

printf("\n\nEnter your expression: ");
gets(str1);
reverse_string(str1);


InitializeStack(&mysatck);

InfixToPrefix(&mysatck,str1,str2);
printf("\n");

reverse_string(str2);

puts(str2);

return 0;
}

void InitializeStack(Stack *s)
{
s->top=NULL;
}
node_t *MakeNode(StackEntry item)
{
node_t *newp;

newp=(node_t*)malloc(sizeof(node_t));
newp->entry=item;
newp->next=NULL;

return(newp);
}
void Push(StackEntry item, Stack *s)
{
node_t *newp=MakeNode(item);

newp->next=s->top;
s->top=newp;
}

boolean StackEmpty(Stack *s)
{
return(s->top==NULL);
}

StackEntry Pop(Stack *s) 
{
node_t *cur_nodep;
StackEntry item;

if(StackEmpty(s))
printf("the stack is empty\n");

else
{
cur_nodep=s->top;
item=cur_nodep->entry;
s->top=s->top->next;
free(cur_nodep);
return (item);
}
}

StackEntry StackTop(Stack *s)
{
StackEntry item;

if(StackEmpty(s))
printf("\nthe stack is empty\n");
else

item=s->top->entry;
}

/*StackEntry nextInput()
{
StackEntry item;

scanf("%c",&item);

return (item);
}*/
int getPriority(StackEntry ch)
{
switch(ch)
{
case '+':
case '-':
return 1;
case '*':
case '/':
return 2; 
}
}
void reverse_string(StackEntry str[])
{
Stack mystack;
int i;

InitializeStack(&mystack);

for(i=0;str[i] != '\0';i++)
Push(str[i],&mystack);

for(i=0;!StackEmpty(&mystack);i++)
str[i]=Pop(&mystack); 
}

void InfixToPrefix(Stack *myStack,StackEntry str1[],StackEntry str2[])
{
int i,j=0;
StackEntry item,temp;
//FILE *inp=fopen("input.txt","r");

for(i=0;str1[i]!='\0';i++)
{
item=str1[i];
switch(item)
{

case '+':
case '-':
case '*':
case '/':
while((!StackEmpty(myStack)) && (StackTop(myStack) != ')' ) && 
(getPriority( StackTop(myStack) ) > getPriority( item )))
str2[j++]=Pop(myStack) ;

Push(item, myStack);
break; 

case ')':
Push(item,myStack);
break; 

case '(':
while((temp = Pop(myStack)) != ')')
str2[j++]=temp;
break; 

default:
str2[j++]=item;
}
}
while(!StackEmpty(myStack)) 
str2[j++]=Pop(myStack);
str2[j]='\0';
//fclose(inp);
} 