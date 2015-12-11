#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;

struct btreenode* insert ( struct btreenode **, int ) ;
struct btreenode* delete ( struct btreenode **, int ) ;
void search ( struct btreenode **, int, struct btreenode **,
                struct btreenode **, int * ) ;
void inorder ( struct btreenode * ) ;
void preorder ( struct btreenode * ) ;
void postorder ( struct btreenode * ) ;
int find(struct btreenode *sr,int num);
int main(int argc,char *argv[])
{
    struct btreenode *bt ;
    int req, i = 0, num ;
    bt = NULL ;  /* empty tree */
    FILE *iptr;
    int data;
    if (argc!=3)
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
				bt=insert(&bt,data);
			}
			fclose(iptr);
		}
	
    printf ( "Binary tree preorder Traversal:\n" ) ;
    preorder ( bt ) ;
    printf("\n");
    printf ( "Binary tree Inorder Traversal:\n" ) ;
    inorder ( bt ) ;
    printf("\n");
    printf ( "Binary tree postorder Traversal:\n" ) ;
    postorder ( bt ) ;
    printf("\n");
    
    if ( (iptr = fopen (argv[1],"r")) == NULL)
    {
        	printf("Error in opening files...");
    }
	else
	{
    while(!feof(iptr))
	{
		fscanf (iptr,"%d", &data);
		bt=delete ( &bt, data ) ;
		printf ( "\nBinary tree after deletion:\n" ) ;
        inorder ( bt ) ;
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
		num=find( bt, data ) ;
		if(num==1)
		printf ( "%dItem Found\n",data) ;
        else
        printf("%dItem Not Found\n",data);
	}
	fclose(iptr);
	}
    
}
return 0;
}
/* inserts a new node in a binary search tree */
struct btreenode* insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;

        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else/* search the node to which new node will be attached */

    {
        /* if new data is less, traverse to left */
        if ( num < ( *sr ) -> data )
            *sr=insert ( &( ( *sr ) -> leftchild ), num ) ;
        else/* else traverse to right */

            *sr=insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
    return(*sr);
}

struct btreenode *getptr(struct btreenode **p, int key, struct btreenode **y) {
    struct btreenode *temp; 
    if( *p == NULL) 
    return(NULL); 
    temp = *p; 
    *y = NULL; 
    while( temp != NULL) 
    { 
        if(temp->data == key) 
            return(temp);
        else 
        { 
            *y = temp;
            /*store this pointer as root */ 
            if(temp->data > key)
                temp = temp->leftchild; 
            else 
                 temp = temp->rightchild; 
         } 
        
    } 
    return(NULL);
    } 
/* A function to delete the node whose data value is given */ 
struct btreenode* delete(struct btreenode **p,int val) 
{ 
    struct btreenode *x, *y, *temp; 
    x = getptr(&(*p),val,&y); 
    if( x == NULL)
    { 
        printf("The node does not exists\n"); 
       // return(*p);
        } 
        else
        { 
            /* this code is for deleting root node*/
            if( x == *p)
            { 
                temp = x->leftchild; 
                y = x->rightchild;
                *p = temp;
                while(temp->rightchild != NULL) 
                temp = temp->rightchild;
                temp->rightchild=y;
                free(x); 
                return(*p);
                }
                /* this code is for deleting node having both children */
                if( x->leftchild != NULL && x->rightchild != NULL) 
                {
                    if(y->leftchild == x)
                    {
                        temp = x->leftchild; 
                        y->leftchild = x->leftchild; 
                        while(temp->rightchild != NULL) 
                        temp = temp->rightchild; 
                        temp->rightchild=x->rightchild; 
                        x->leftchild=NULL; 
                        x->rightchild=NULL; 
                        
                    } 
                    else
                    {
                        temp = x->rightchild;
                        y->rightchild = x->rightchild; 
                        while(temp->leftchild != NULL)
                        temp = temp->leftchild; 
                        temp->leftchild=x->leftchild; 
                        x->leftchild=NULL; x->rightchild=NULL; 
                        
                    }
                    free(x); 
                    return(*p); 
                    
                } 
                /* this code is for deleting a node with on child*/ 
                if(x->leftchild == NULL && x->rightchild != NULL)
                { 
                    if(y->leftchild == x) 
                        y->leftchild = x->rightchild;
                    else 
                        y->rightchild = x->rightchild;
                        x->rightchild = NULL; 
                        free(x); 
                        return(*p);
                } 
                if( x->leftchild != NULL && x->rightchild == NULL) 
                { 
                    if(y->leftchild == x)
                    y->leftchild = x->leftchild ; 
                    else
                    y->rightchild = x->leftchild; 
                    x->leftchild = NULL; 
                    free(x); 
                    return(*p); 
                    
                } 
                /* this code is for deleting a node with no child*/ 
                if(x->leftchild == NULL && x->rightchild == NULL) 
                {
                    if(y->leftchild == x) 
                    y->leftchild = NULL ;
                    else 
                    y->rightchild = NULL; 
                    free(x);
                   return(*p); 
                    
                } 
            
        }
    }

/*Search the reacord based on the root,call the function recursively 
to find the data */
int find(struct btreenode *sr,int num)
{
    
    if(sr==NULL)
        return 0;
    else if(sr->data==num)
        return 1;
    else if(num<sr->data)
        find(sr->leftchild,num);
    else
        find(sr->rightchild,num);
} 

/* traverse a binary search tree in a LDR (Left-Data-Right) fashion */
void inorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ) ;

        /* print the data of the node whose leftchild is NULL or the path  has
            already been traversed */

        printf ( "%d\t", sr -> data ) ;

        inorder ( sr -> rightchild ) ;
    }
}

/* traverse a binary search tree in a DLR (Data-Left-Right) fashion */
void preorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        printf ( "%d\t", sr -> data ) ;

        preorder ( sr -> leftchild ) ;
        preorder ( sr -> rightchild ) ;
    }
}

/* traverse a binary search tree in a LRD (Left-Right-Data) fashion */
void postorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        postorder ( sr -> leftchild ) ;
        postorder ( sr -> rightchild ) ;
        printf ( "%d\t", sr -> data ) ;
    }
}