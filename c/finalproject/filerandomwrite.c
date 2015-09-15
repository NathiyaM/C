#include<stdio.h>
struct Student{
char FirstName[15];
char LastName[15];
char middlename[15];
int quiz1,quiz2,quiz3,quiz3,quiz4,mid,midii,final;
};
int main(void)
{
	FILE *cfptr;
	struct student records ={"","","",0,0,0,0,0,0,0};
	if((cfptr=fopen("inputfile.txt","r"))==NULL)
	{
		printf("The file cannot be opened");
	}
	else
	{
		fprintf(cfptr,"%-15s%-15s%-15s%d%d%d%d%d%d%d","FIRST NAME","MIDDLE NAME","LAST NAME","QUIZ1","QUIZ2","QUIZ3","QUIZ4","MID","MIDII","FINAL");
		while(!feof(cfptr))
		{
			fread(&records,sizeof(struct Student),1,cfptr);
			fprintf(cfptr,"%-15s%-15s%-15s%d%d%d%d%d%d%d",records.FirstName,records.LastName,records.middlename,records.quiz1,records.quiz2,records.quiz3,records.quiz3,records.quiz4,records.mid,records.midii,records.final);
		}
    fclose(cfptr);
}
return 0;
}


