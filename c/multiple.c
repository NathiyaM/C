# include <stdio.h>
int main()
{
int a,b;
float mod;
printf("Input two different integers:");
scanf("%d%d",&a,&b);
mod = a%b;
if(mod==0) {
printf("%d is multiple of %d\n",a,b);
}
if(mod!=0) {
printf("%d is not a multiple of %d\n",a,b);
}
}

