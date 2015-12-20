/*****************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension,Santa Cruz                     	*/
/*                                                                              */
/*                                                                              */
/* 			Advanced C Programming                                              */
/*                                                                              */
/* 			Instructor :Rajainder A.Yeldandi							        */
/*                                                                              */
/* 			Author:Nathiya Meganathan										    */
/*								            	 									                                      	*/
/*			Assignment No:		19      									    */
/*																			                                      	*/
/*			Topic:shortestpath									                */
/*	    								                                      	*/
/*			FileName:shortestpath.c							               		*/
/*			Date of the Program:12.10.2015										*/
/*			Objective: read the input and print the distance matrix only for 
            the nodes given in the map. • Show at each step what is the next 
            node considered in the path to destination. • 
            Print the total distance from starting node to terminating node 
            giving distance between intermediate nodes. 					    */						                            
/********************************************************************************/  
//Predefined directives.


#include<stdio.h>
#define INFINITY 2000
#define MAXNODES 8
#define MEMBER 1
#define NONMEMBER 0
void shortpath(int weight[][MAXNODES], int , int ,int * ,int precede[]);
int main(void)
{
   int i,j,s,t,choice=1;
   int weight[MAXNODES][MAXNODES]={0},precede[MAXNODES],pd;
   while(choice==1)
        {
           printf("Enter the nodes you wish to enter distance between nodes:");
           scanf("%d%d",&i,&j);
           printf("Enter the weightage for node%d -----> node %d:",i,j);
           scanf("%d",&weight[i][j]);
           printf("\n");
           printf("Do you wish to continue:T(1)/F(0):");
           scanf("%d",&choice);
        }    

   for(i=0;i<MAXNODES;i++)
   {
     printf("\n");
     for(j=0;j<MAXNODES;j++)
        {
            if(weight[i][j]==0)
                weight[i][j]=INFINITY;
            printf(" %d",weight[i][j]);
        }
   }
   printf("\n Enter the starting node and the ending node: ");
   scanf(" %d %d",&s,&t);
   shortpath(weight,s,t,&pd,precede);
   printf("\n The shortest path from node %d to %d is : %d",s,t,pd); 
   return(0);
}
void shortpath(int weight[][MAXNODES],int s, int t, int *pd, int precede[])
{
  int distance[MAXNODES],perm[MAXNODES];
  int current,i,j,k,dc;
  int smalldist,newdist;
  /* initialization of perm and distance array */
  for(i=0;i<MAXNODES;i++)
  {
   perm[i]=NONMEMBER;
   distance[i]=INFINITY;
  }
  perm[s] = MEMBER;
  distance[s] = 0;
  current = s;
  while(current != t)
  {
   smalldist=INFINITY;
   dc=distance[current];
   for(i=0;i<MAXNODES;i++)
     if(perm[i]==NONMEMBER)
     {
      newdist = dc + weight[current][i];
      if(newdist < distance[i])
      {
       distance[i]=newdist;
       precede[i]=current;
      }
      if(distance[i] < smalldist)
      {
       smalldist = distance[i];
       k=i;
      }
    } /* end of for if */
    current = k;
    perm[current]=MEMBER;
   }  /* END WHILE */
   *pd=distance[t];
}    /* end of shortpath function */
/* END OF PROGRAM */
 
