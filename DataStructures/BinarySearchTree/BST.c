#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//Strcutre declaration of nodes
struct Node {
    int data;
   struct Node *left;
    struct Node *right;
};
typedef struct Node Node;
//Function Prototypes
void insertnode(Node *root,int data);
//void search(Node *root,int data);
Node* getnewnode(int data);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
//main function
int main(int argc,char *argv[])
{
    
    Node *root=NULL;
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
				insertnode(root,data);
			}
			fclose(iptr);
			printf("The Data are displayed in preorder traversal\n");
			preorder(root);
			printf("The Data are displayed in Inorder traversal\n");
			inorder(root);
			printf("The Data are displayed in postorder traversal\n");
			postorder(root);
		}
	}
	return 0;
}

Node* getnewnode(int data)
{
    Node* newnode;
    newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

/*Function to insert the node into the tree,
if the root greater the node ,insert the data to the right side 
of the node assign right and left node to null ,similarly,if the 
root node data less than the data then create create the node on the 
left insert the data on the left node */
void insertnode(Node *root,int data)
{
    if(root==NULL)
    {
        root=getnewnode( data);
    }
    else if(data < root->data)
    {
        insertnode(root->left, data);
    }
    else
    {
        insertnode(root->right,data);
    }
    
}
/*Search the reacord based on the root,call the function recursively 
to find the data */
/*int search(Node *root,int data)
{
    if(root==NULL)
        return 0;
    else if(root->data==data)
        return 1;
    else if(data<root->data)
        search(root->left,data);
    else
        search(root->right,data);
} */

/*Display the data from root,left node,right node*/
void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

/*Display the data from left node,root,right node*/
void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

/*Display the data from left node,right node,root*/
void postorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}