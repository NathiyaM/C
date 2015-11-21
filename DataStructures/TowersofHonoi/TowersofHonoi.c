/********************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension,Santa Cruz                       */
/*                                                                              */
/*                                                                              */
/*          Advanced C Programming                                              */
/*                                                                              */
/*          Instructor :Rajainder A.Yeldandi                                    */
/*                                                                              */
/*          Author:Nathiya Meganathan                                           */
/*                                                                              */
/*          Assignment No:10                                                    */
/*                                                                              */
/*          Topic:Recursion                                                     */
/*                                                                              */
/*          FileName:TowersofHonoi.                                             */
/*          Date of the Program:10.30.2015                                      */
/*          Objective:prompt the user to give the number of disks to be 	    	*/
/*			    placed on the target post from the initial post using the     		 	*/	
/*		    	auxilary post.                                 										  */
/*               															                                	 */
/********************************************************************************/

/* Preprocessor Directives */


#include <stdio.h>
 
void towers(int, char, char, char);
//start of the main function 
int main()
{
    int num;
 	printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'B', 'C');
    return 0;
}

void towers(int num, char source, char auxi, char dest)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", source, dest);
        return;
    }
    //recursion function call
	towers(num - 1, source,dest,auxi);
    printf("\n Move disk %d from peg %c to peg %c", num, source,dest);
    //recursion function call
	towers(num - 1, auxi, source,dest);
    //recursion function call
}
