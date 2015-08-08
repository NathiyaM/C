#include<stdio.h>
int main()
{
	int product=1,quantity;
    float price,Total_Amount=0,amount;
	while(product>0)
	{
	printf("Enter pair of item numbers and quantities:");
	scanf("%d",&product);
	if(product==-1)
	break;
	scanf("%d",&quantity);
	switch(product)
	{
	case 1:
	price = 2.98;
	amount=quantity*price;
	break;
	case 2:
	price = 4.50;
	amount=quantity*price;
	break;
	case 3:
	price = 9.98;
	amount=quantity*price;
	break;
	case 4:
	price = 4.49;
	amount=quantity*price;
	break;
	case 5:
	price = 6.87;
	amount=quantity*price;
	break;
	default:
	amount = 0;
	printf("Invalid Product code%d\n%d:",product,quantity);
	break;
}
Total_Amount = amount+Total_Amount;
}				
printf("%.2f\nTotalretailprice",Total_Amount);
	return 0;
}
