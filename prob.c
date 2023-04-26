#include<stdio.h>
main()
{
 int n,i;
 n=f(6);
 printf("%d",n);
}
f(int x)
{
 if(x==2)
 return 2;
 else
 {
 printf("x");
 f(x-1);
 }
}