#include<stdio.h>
void main()
{
int TotMiles,CostPerGallon,ParkingFee,TollPerDay;
float AverageMilePerGallon,GallonConsumedPerDay,DailyCost;
printf("Total miles driven per day:");
scanf("%d",&TotMiles);
printf("Cost per gallon of gasoline:");
scanf("%d",&CostPerGallon);
printf("Average miles per gallon:");
scanf("%f",&AverageMilePerGallon);
printf("Parking fees per day:");
scanf("%d",&ParkingFee);
printf("Tolls per day:");
scanf("%d",&TollPerDay);

/*Calculates the Daily cost */

GallonConsumedPerDay=TotMiles/AverageMilePerGallon;
DailyCost=(GallonConsumedPerDay*CostPerGallon)+(ParkingFee+TollPerDay);
printf("Your Daily cost of driving to work is %f\n",DailyCost);
}


