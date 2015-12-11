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
  //  return(*sr);
}

void delete_node(struct btreenode **node, int value)
{
	struct btreenode *current = NULL, *del_node = NULL, *child = NULL;
	struct btreenode *parent = NULL, *x = NULL;
	
	current = *node; 		
	
	while (current != NULL) {		
		if (value == current->data) {
		del_node = current;
		//case 1: node is a leaf (no descendants)
			if ((del_node->leftchild == NULL) && (del_node->rightchild == NULL)) {
				//if the node to delete is to the left of root
				if (parent->leftchild == del_node) {
					parent->leftchild = NULL;
					free(del_node);
					printf("Node deleted\n");
				//	break;
				}
				//if the node to delete is to the right of root
				else if (parent->rightchild == del_node) {
					parent->rightchild = NULL;
					free(del_node);
					printf("Node deleted\n");
				//	break;
				}
			}
		//case 2: node has one child
			else if ((del_node->leftchild == NULL) || (del_node->rightchild == NULL)) {
				printf("Node has one child\n");
				//if the node to delete is to the left of root
				if (parent->leftchild == del_node) {
					if (del_node->leftchild != NULL) {
						child = del_node->leftchild;
						parent->leftchild = child;
						free(del_node);
					//	break;
					}
					else if (del_node->rightchild != NULL) {
						child = del_node->rightchild;
						parent->leftchild = child;
						free(del_node);
					//	break;
					}
				}
				//if the node to delete is to the right of root
				else if (parent->rightchild == del_node) {
					if (del_node->leftchild != NULL) {
						child = del_node->leftchild;
						parent->rightchild = child;
						free(del_node);
					//	break;
					}
					else if (del_node->rightchild != NULL) {
						child = del_node->rightchild;
						parent->rightchild = child;
						free(del_node);
					//	break;
					}
				}						
			}
		//case 3: node has two children	
			else if ((del_node->leftchild != NULL) && (del_node->rightchild != NULL)) {
				printf("Node has two children\n");
				x = del_node;
				//if the node to delete is root
				if (parent == NULL) {
					child = del_node->rightchild;
					if (child->leftchild == NULL) {
						child->leftchild = del_node->leftchild;
						free(del_node);
					//	break;
					}
					else {
						while (child->leftchild != NULL) {
								parent = child;
								child = parent->leftchild;
						}
						x->data = child->data;
						parent->leftchild = child->rightchild;
						del_node = child;
						free(del_node);
						//break;
					}						
				}
				//if the node to delete is to the left of root
				else if (parent->leftchild == del_node) {
					child = del_node->rightchild;
					if (child->leftchild == NULL) {
						parent->leftchild = child;
						child->leftchild = del_node->leftchild;
						free(del_node);
					//	break;
					}
					else {
						while (child->leftchild != NULL) {
								parent = child;
								child = parent->leftchild;
						}
						x->data = child->data;
						parent->leftchild = child->rightchild;
						del_node = child;
						free(del_node);
					//	break;
					}
				}
				//if the node to delete is to the right of root
				else if (parent->rightchild == del_node) {
					child = del_node->rightchild;
					if (child->leftchild == NULL) {
						parent->rightchild = child;
						child->leftchild = del_node->leftchild;
						free(del_node);
					//	break;
					}
					else {
						while (child->leftchild != NULL) {
								parent = child;
								child = parent->leftchild;
						}
						x->data = child->data;
						parent->leftchild = child->rightchild;
						del_node = child;
						free(del_node);
					//	break;
					}
				}
			}		
		}
		//if value is less than the node's value - go left
		else if (value < current->data) {
			parent = current;
			current = current->leftchild;
		}
		//if value is greater than the node's value - go right
		else {
			parent = current;
			current = current->rightchild;
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