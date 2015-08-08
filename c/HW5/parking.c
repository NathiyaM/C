#include<stdio.h>
float calculate_charges(float hours);//function prototype
int main()
{
float hr,charge,tot_charge=0,tot_hour=0,car=0;
printf("car\tHour\tCharge\n");
scanf("%f",&hr);
while(hr!=-1)
{	
	car++;
	charge=calculate_charges(hr);
	printf("%.2f\t%.2f\t%.2f\n",car,hr,charge);
	tot_hour=tot_hour+hr;
	tot_charge=tot_charge+charge;
	scanf("%f",&hr);
}
printf("Total\t%.2f\t%.2f",tot_hour,tot_charge);
return 0;
}
//function definitions

float calculate_charges(float hours)
{
float charge;
if(hours<=3.00)
	{
	charge=2.00;
	return charge;
	}
else if(hours==24.00)
	{
	charge = 10.00;
	return charge;
	}
else
	{
	charge = ((hours-3.00)*0.50)+2.00;
	return charge;
	}
}


