/********************************************************************************/
/************************** Prologue ********************************************/
/*                                                                              */
/*          University of California Extension,Santa Cruz                   	*/
/*                                                                              */
/*                                                                              */
/* 			Advanced C Programming                                           	*/
/*                                                                              */
/* 			Instructor :Rajainder A.Yeldandi									*/
/*                                                                              */
/* 			Author:Nathiya Meganathan											*/
/*																				*/
/*			Assignment No:4														*/
/*																				*/
/*			Topic:Structure														*/
/*																				*/
/*			FileName:StudentStatics.c											*/
/*																				*/	
/*			Date of the Program:10.24.2015										*/
/*																				*/
/*			Objective:Call functions to find the average, minimum, and          */
/*			maximum score for each student. Call a								*/
/*			function to assign the student number using a						*/
/*			static variable for the student number which						*/
/*			will automatically increment whenever the							*/
/*			function is called. Show the student number 						*/
/*			along with the statics for the scores. Find the 					*/
/*			average, minimum, and maximum for all				    			*/
/*			students. Print all scores for each student.						*/
/*			Write all the output to a file. Assign a letter			    		*/
/*			grade for each score and print. 									*/
/*																				*/
/********************************************************************************/  

/* Preprocessor Directives */

#include<stdio.h>
#define SIZE 6
/* Declaration of Structure Members */
struct student
{
float final_score,min,max,average;
int score[10];
int RollNumber;
char *grade;
}record[SIZE];
void split_studentrecord(int score[],int size,struct student record[],int n);
void final_score(struct student record[],int n);//function prototype 
void grade(struct student record[],int n);//function prototype
void maximum_mark(struct student record[],int n);//function prototype
void minimum_mark(struct student record[],int n);//function prototype
void display_records(struct student record[],int n,char *argv[]);
int main(int argc,char *argv[])
{
	FILE *iptr,*fptr;
	int i,number,j;
	int StudentScore[80];
	//validate the arguments not equal to 3
    if(argc!=3)
    {
        printf("Usage:  %s  inputFileName   outputFileName\n",argv[0]);
        exit(1);
    }
//if entered arguments are valid,open the file read the student record from argv[1] file  and split the records as name,marks and store them in structure.
    else
    {
        if((iptr=fopen(argv[1],"r"))==NULL)
        {
printf("Error in opening files...");
        }
        else
        {
			for(i=0;i<60;i++)
			{
				fscanf(iptr,"%d,",&StudentScore[i]);
			}
		}
		for(i=0;i<60;i++)
		{
			printf("%d\t",StudentScore[i]);
		}
		fclose(iptr);//closing of reading file
		split_studentrecord(StudentScore,60,record,SIZE);//function calling
	//	display_records(record,SIZE,argv[]);
		final_score(record,SIZE);
		maximum_mark(record,SIZE);
		minimum_mark(record,SIZE);
    	if((fptr=fopen(argv[2],"w"))==NULL)
    	{
        	printf("The file can't be opened for writing");
    	}
		//writing the records with student name and grade into the output file
   		 else
    	{
        fprintf(fptr,"ROLLNUMBER \t\t SCORE \t\t GRADE \t\t MAXIMUM \t\t MINIMUM \t\t AVERAGE\n");
    	for(i=0;i<SIZE;i++)
    	{
        	fprintf(fptr,"%d\t",record[i].RollNumber);
        	for(j=0;j<10;j++)
        	{
            	fprintf(fptr,"%d\t",record[i].score[j]);
            	fprintf(fptr,"%s\t",record[i].grade);
        	}
        	fprintf(fptr,"%.2f\t%.2f\t%.2f\t\n",record[i].max,record[i].min,record[i].average);
        	printf("\n");
    	}
    	}
    	fclose(fptr);
		}
	return 0;
}

//function definitions
void split_studentrecord(int score[],int size,struct student record[],int n)
{
	int StudentNumber=1000,incr=0,startindex=0;
	int index=0,number,i,j;
	printf("Enter the number of students to show the statics\n");
    scanf("%d",&number);	
	for(i=0;i<number;i++)
	{
		StudentNumber=StudentNumber+1;
		record[i].RollNumber=StudentNumber;
		//printf("%d",record[i].RollNumber);
		for(j=startindex;j<incr+10;j++)
		{
			record[i].score[index]=score[j];
			//printf("\t%d\t",record[i].score[j]);
			printf("%d",index);
			index+=1;
		}
		printf("\n");
		startindex+=10;
		incr+=10;
		index=0;
	}
}
/*
void display_records(struct student record[],int n,char *argv[])
{
	int i,j;
	}
*/
//function definition for calculating the final score and store into structure.
void final_score(struct student record[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
			record[i].final_score=0;
		for(j=0;j<10;j++)
		{	
			if(record[i].score[j]>95)
				{
				record[i].grade="A+";
				}
			else if(record[i].score[j]=95)
				{record[i].grade="A";}
			else if(record[i].score[j]>=90)
				{record[i].grade="A-";}
			else if(record[i].score[j]>85)
				{record[i].grade="B+";}
			else if(record[i].score[j]=85)
				{record[i].grade="B";}
			else if(record[i].score[j]>=80)
				{record[i].grade="B-";}	
			else if(record[i].score[j]>75)
				{record[i].grade="C+";}
			else if(record[i].score[j]=75)
				{record[i].grade="C";}
			else if(record[i].score[j]>=70)
				{record[i].grade="C-";}
			else if(record[i].score[j]>=60)
				{record[i].grade="D";}
			else if(record[i].score[j]<60)
				{record[i].grade="F";}
		/* calculate the final score to find the average of the score by the single student.*/	
		record[i].final_score=record[i].final_score+record[i].score[j];
    	}
			record[i].average=record[i].final_score/10;
    		printf("The final score is%.2f\t%.2f",record[i].final_score,record[i].average);
	}
}

//function definition for calculating the maximum mark and result into the screen.
void maximum_mark(struct student record[],int n)
{
    int i,j;
    printf("Maximum:\t");
    for(i=0;i<n;i++)
    {
		record[i].max=0;
        for (j=0;j<10;j++)
        {
            if(record[i].score[j]>record[i].max)
            {
                record[i].max=record[i].score[j];
            }
        }
        printf("%.2f\t",record[i].max);
    }
    printf("\n\n");
}

//function definition for calculating the minimum mark and printing the result into the screen.
void minimum_mark(struct student record[],int n)
{
    int i,j;
 	printf("Minimum:\t");
    for(i=0;i<n;i++);
    {
		record[i].min=0;
        for(j=0;j<10;j++)
        {
            if(record[i].min==0)
            {
                record[i].min=record[i].score[j];
            }
            else if(record[i].score[j]<record[i].min)
            {
                record[i].min=record[i].score[j];
            }
        }
        printf("%.2f\t",record[i].min);
    }
    printf("\n");
}
