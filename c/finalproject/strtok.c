#include <stdio.h>
#include <string.h>
# define SIZE 100
/*declaration of structure members*/
struct student
{
char name[50];
int  quiz[7];
float final_score;
char grade;
}record[SIZE];

void final_score(struct student record[],int n);//function prototype 
void grade(struct student record[],int n);//function prototype
void maximum_mark(struct student record[],int n);//function prototype
void minimum_mark(struct student record[],int n);//function prototype
void average(struct student record[],int n);//function prototype
void sort(struct student record[],int n);//function prototype
int main(int argc,char *argv[])//main function with command line arguments
{
//variable declaration
	char name[30];
	char line[100];
	char *field;
	FILE *fptr,*cfptr;
	int i,index,recordindex;
//validate the arguments not equal to 3
	if(argc!=3)
	{
		printf("Usage:	%s	inputFileName	outputFileName\n",argv[0]);
		exit(1);
	}
//if entered arguments are valid,open the file read the student record from argv[1] file  and split the records as name,marks and store them in structure.
	else
	{
		if((fptr=fopen(argv[1],"r"))==NULL)
		{
			printf("Error in opening files...");
		}
		else	
		{
			recordindex=0;
			while(fgets(line,sizeof(line),fptr)!=NULL)
			{   
				index=0;
				field=strtok(line,",");//extracting the records with ,
				while(field!=NULL)
				{
					if (index==0)
					{
						strcpy(record[recordindex].name,field);
						field=strtok(NULL,",");
					}
					else
					{
						record[recordindex].quiz[index-1]=atoi(field);//converting the string of mark into int type
						field=strtok(NULL,",");
						
					}
					index++;	
				}
				recordindex++; 
			}
			printf("%dno of records",recordindex);
			fclose(fptr);
			}
		}
	
	final_score(record,recordindex);//function declaration for calculating total marks
	grade(record,recordindex);//function declaration for calculating grade
	printf("\n%20s%s","Q1\t","Q2\tQ3\tQ4\tMid\tMidii\tFinal\n\n");	
	average(record,recordindex);//function declaration for calculating average
    minimum_mark(record,recordindex);//function declaration for calculating minimum_mark
	maximum_mark(record,recordindex);//function declaration for calculating maximum mark
	//sort(record,recordindex);
	if((cfptr=fopen(argv[2],"w"))==NULL)
	{
		printf("The file can't be opened for writing");
	}
//writing the records with student name and grade into the output file
	else
	{
		for(i=0;i<recordindex;i++)
		{
			fprintf(cfptr,"%-30s\t%-5c\n",record[i].name,record[i].grade);
		}	
	}
	fclose(cfptr);	
return 0;
}
//function definition for calculating the final score and store into structure.
void final_score(struct student record[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		record[i].final_score=(record[i].quiz[0]*.10)+(record[i].quiz[1]*.10)+(record[i].quiz[2]*.10)+(record[i].quiz[3]*.10)+(record[i].quiz[4]*.20)+(record[i].quiz[5]*.15)+(record[i].quiz[6]*.25);
	//	printf("The final score is%.2f\n",record[i].final_score);
	}
}

//function definition for calculating the grade and store into structure.
void grade(struct student record[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(record[i].final_score>=90)
		{
			record[i].grade='A';
			//printf("The grade is %c",record[i].grade);
		}
		else if(record[i].final_score<90 && record[i].final_score >=80)
		{	
			record[i].grade='B';
		}
		else if(record[i].final_score<80 && record[i].final_score>=70)
		{
			record[i].grade='C';
		}
		else if(record[i].final_score<70 && record[i].final_score>=60)
		{
			record[i].grade='D';
		}
		else if(record[i].final_score<60)
		{
			record[i].grade='F';
		}
	}
}

//function definition for calculating the maximum mark and result into the screen.
void maximum_mark(struct student record[],int n)
{
	int i,index=0,max=0;
	printf("Maximum:\t");
	while(index<7)
	{
		for (i=0;i<n;i++)
		{
			if(record[i].quiz[index]>max)
			{
				max=record[i].quiz[index];
			}
		}
 		printf("%d\t",max);
		index++;
		max=0;
	}	
	printf("\n\n");
}

//function definition for calculating the minimum mark and printing the result into the screen.
void minimum_mark(struct student record[],int n)
{
	int i,index=0,min=0;
	printf("Minimum:\t");
	while(index<7)
	{
		for(i=0;i<n;i++)
		{
			if(min==0)
			{
				min=record[i].quiz[index];
			}
			else if(record[i].quiz[index]<min)
			{
				min=record[i].quiz[index];
			}
		}
		printf("%d\t",min);
		index++;
		min=0;
	}
	printf("\n");
}

//function definition for calculating the average score.
void average(struct student record[],int n)
{
	int i,index=0,count=0;
	float avg,total=0;
	printf("Average:\t");
	while(index<7)
	{
		for(i=0;i<n;i++)
		{
			total+=record[i].quiz[index];
			count = count+1;
		}
		avg=total/count;
		printf("%.2f\t",avg);
		index++;
		total=count=0;
	}
	printf("\n");
}
							
//function definition for sorting the student record in alphabeetical order and store into structure.
void sort(struct student record[],int n)
{
	int i,j;
	char tmp[50];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			{
				if(strcmp(record[j].name,record[j+1].name)>0)
					{
						strcpy(tmp,record[j].name);
						strcpy(record[j].name,record[j+1].name);
						strcpy(record[j+1].name,tmp);
					}
				printf("%s\t",record[j].name);
			}
	}
}
	

