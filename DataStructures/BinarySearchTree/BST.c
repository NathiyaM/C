#include <stdio.h>
#include <stdlib.h>

  struct treeNode {
        int data;
        struct treeNode *left, *right;
  };

  struct treeNode *root = NULL;

  /* create a new node with the given data */
  struct treeNode* createNode(int data) {
        struct treeNode *newNode;
        newNode = (struct treeNode *) malloc(sizeof (struct treeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return(newNode);
  }

  /* insertion in binary search tree */
  void insertion(struct treeNode **node, int data) {
        if (*node == NULL) {
                *node = createNode(data);
        } else if (data < (*node)->data) {
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) {
                insertion(&(*node)->right, data);
        }
  }


  /* deletion in binary search tree */
  void deletion(struct treeNode **node, struct treeNode **parent, int data) 
  {
        struct treeNode *tmpNode, *tmpParent;
        if (*node == NULL)
                return;
        if ((*node)->data == data) {
                /* deleting the leaf node */
                if (!(*node)->left && !(*node)->right) {
                        if (parent) {
                                /* delete leaf node */
                                if ((*parent)->left == *node)
                                        (*parent)->left = NULL;
                                else
                                        (*parent)->right = NULL;
                                free(*node);
                        } else {
                                /* delete root node with no children */
                                free(*node);
                        }
                /* deleting node with one child */
                } 
                else if (!(*node)->right && (*node)->left) {
                        /* deleting node with left child alone */
                        tmpNode = *node;
                        (*parent)->right = (*node)->left;
                        free(tmpNode);
                        *node = (*parent)->right;
                } 
                else if ((*node)->right && !(*node)->left) {
                        /* deleting node with right child alone */
                        tmpNode = *node;
                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        (*node) = (*parent)->left;
                } 
                else if (!(*node)->right->left) 
                {
                        /*
                         * deleting a node whose right child
                         * is the smallest node in the right
                         * subtree for the node to be deleted.
                         */

                        tmpNode = *node;

                        (*node)->right->left = (*node)->left;

                        (*parent)->left = (*node)->right;
                        free(tmpNode);
                        *node = (*parent)->left;
                } else {
                        /*
                         * Deleting a node with two children.
                         * First, find the smallest node in
                         * the right subtree.  Replace the 
                         * smallest node with the node to be
                         * deleted. Then, do proper connections
                         * for the children of replaced node.
                         */
                        tmpNode = (*node)->right;
                        while (tmpNode->left) {
                                tmpParent = tmpNode;
                                tmpNode = tmpNode->left;
                        }
                        tmpParent->left = tmpNode->right;
                        tmpNode->left = (*node)->left;
                        tmpNode->right =(*node)->right;
                        free(*node);
                        *node = tmpNode;
                }
        } 
        else if (data < (*node)->data)
        {
                /* traverse towards left subtree */
                deletion(&(*node)->left, node, data);
        } 
        else if (data > (*node)->data)
        {
                /* traversing towards right subtree */
                deletion(&(*node)->right, node, data);
        }
  }

  /* search the given element in binary search tree */
  void findElement(struct treeNode *node, int data) {
        if (!node)
                return;
        else if (data < node->data) {
                findElement(node->left, data);
        } else if (data > node->data) {
                findElement(node->right, data);
        } else
                printf("data found: %d\n", node->data);
        return;

  }

  void inorder(struct treeNode *node) {
        if (node != NULL) {
                inorder(node->left);
                printf("%d\t", node->data);
                inorder(node->right);
        }
        return;
  }

  void preorder(struct treeNode *node) 
  {
        if (node != NULL) 
        {
            printf("%d\t", node->data);
            preorder(node->left);
            preorder(node->right);
        }
        
        return;
  }
  
void postorder(struct treeNode *node) 
  {
        if (node != NULL) {
            
            postorder(node->left);
            postorder(node->right);
            printf("%d\t", node->data);
        }
        
        return;
  }
  
  int main(int argc,char *argv[])
  {
        int data,i;
        FILE *iptr;
                                
        if ( (iptr = fopen (argv[1],"r")) == NULL)
        {
        	printf("Error in opening files...");
        }
		else
	    {
		    while(!feof(iptr))
		    {
			    fscanf (iptr,"%d", &data);
				insertion(&root, data);
			 }
		
		          fclose(iptr);
	    }
	                   
                                printf("Inorder Traversal:\n");
                                inorder(root);
                                printf("\n");
                                printf("Preorder Traversal:\n");
                                preorder(root);
                                printf("\n");
                                printf("Postorder Traversal:\n");
                                postorder(root);
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
                                deletion(&root, NULL, data);
        
		                    	}
		                    	printf("Data after deletion in Inorder Traversal format:\n");
                                inorder(root);
		                    	fclose(iptr);
	                    	}
	                   /*
                                printf("Enter value for data:");
                                scanf("%d", &data);
                                findElement(root, data);
                                
                        
                     */
                                    
        return 0;

  }
