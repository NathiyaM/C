# include <stdio.h>
int main(void)
{
float milesdriven,gallonsused,miles_gallon,total,average;
int counter =total= 0;
gallonsused=0;

while (gallonsused >=0)
{
	printf("enter the gallons used:\n");
	scanf("%f",&gallonsused);
	if(gallonsused==-1)
	{
	break;
	}
	printf("enter the miles driven\n");
	scanf("%f",&milesdriven);
	miles_gallon=milesdriven/gallonsused;
	printf("The miles per gallon for this tank was %f\n",miles_gallon);
	counter++;
	total = miles_gallon+total;
}
average = total/counter;
printf("The average milespergallon was %f\n",average);
}
