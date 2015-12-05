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

void insert ( struct btreenode **, int ) ;
void delete ( struct btreenode **, int ) ;
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
				insert(&bt,data);
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
    /*
    if ( (iptr = fopen (argv[1],"r")) == NULL)
    {
        	printf("Error in opening files...");
    }
	else
	{
    while(!feof(iptr))
	{
		fscanf (iptr,"%d", &data);
		delete ( &bt, data ) ;
		printf ( "\nBinary tree after deletion:\n" ) ;
        inorder ( bt ) ;
	}
	fclose(iptr);
	} */
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
void insert ( struct btreenode **sr, int num )
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
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else/* else traverse to right */

            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

/* deletes a node from the binary search tree */
/*
void delete ( struct btreenode **root, int num )
{
    int found ;
    struct btreenode *parent, *x, *xsucc ;

    /* if tree is empty */ 
    /*
if ( *root == NULL )
    {
        printf ( "\nTree is empty" ) ;
        return ;
    }

    parent = x = NULL ;

    /* call to search function to find the node to be deleted */

 /*   search ( root, num, &parent, &x, &found ) ;

    /* if the node to deleted is not found */
/*if ( found == FALSE )
    {
        printf ( "\nData to be deleted, not found" ) ;
        return ;
    }

    /* if the node to be deleted has two children */
/*if ( x -> leftchild != NULL && x -> rightchild != NULL )
    {
        parent = x ;
        xsucc = x -> rightchild ;

        while ( xsucc -> leftchild != NULL )
        {
            parent = xsucc ;
            xsucc = xsucc -> leftchild ;
        }

        x -> data = xsucc -> data ;
        x = xsucc ;
    }

    /* if the node to be deleted has no child */
/*if ( x -> leftchild == NULL && x -> rightchild == NULL )
    {
        if ( parent -> rightchild == x )
            parent -> rightchild = NULL ;
        else
            parent -> leftchild = NULL ;

        free ( x ) ;
        return ;
    }

    /* if the node to be deleted has only rightchild */
/*if ( x -> leftchild == NULL && x -> rightchild != NULL )
    {
        if ( parent -> leftchild == x )
            parent -> leftchild = x -> rightchild ;
        else
            parent -> rightchild = x -> rightchild ;

        free ( x ) ;
        return ;
    }

    /* if the node to be deleted has only left child */
/*if ( x -> leftchild != NULL && x -> rightchild == NULL )
    {
        if ( parent -> leftchild == x )
            parent -> leftchild = x -> leftchild ;
        else
            parent -> rightchild = x -> leftchild ;

        free ( x ) ;
        return ;
    }
}

/*returns the address of the node to be deleted, address of its parent and
   whether the node is found or not */
void search ( struct btreenode **root, int num, struct btreenode **par, struct
        btreenode **x, int *found )
{
    struct btreenode *q ;

    q = *root ;
    *found = FALSE ;
    *par = NULL ;

    while ( q != NULL )
    {
        /* if the node to be deleted is found */
if ( q -> data == num )
        {
            *found = TRUE ;
            *x = q ;
            return ;
        }

        *par = q ;

        if ( q -> data > num )
            q = q -> leftchild ;
        else
            q = q -> rightchild ;
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