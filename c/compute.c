# include <stdio.h>
int main()
{
int a,b,c,sum;
float average;
printf("Input three different integers:");
scanf("%d%d%d",&a,&b,&c);
sum=a+b+c;
average = sum/3;
printf("The sum is %d\n",sum);
printf("The average is %f\n",average);
printf("The Product is %d\n",a*b*c);
if(a>b && a>c) {
printf("%d is larger\n",a);
}
if(b>a && b>c) {
printf("%d is larger\n",b);
}
if (c>a && c>b) {
printf("%d is larger\n",c);
}
if(a<b && a<c) {
printf("%d is smaller\n",a);
}
if(b<a && b<c) {
printf("%d is Smaller\n",b);
}
if(c<a && c<b) {
printf("%d is smaller\n",c);
}
}
