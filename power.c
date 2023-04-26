#include<stdio.h>
int power1(int a,int n)
{
    int i,p=1,c=0;
    for(i=0;i<n;i++)
    {
        p=p*a;
        c++;
    }
    printf("Power of %d is %d\n",a,p);
    return c;
}
int power2(int a,int n)
{
    int p=1,q=a,c=0;
    while(n>0)
    {
        if(n%2!=0)
            p=p*q;
        n=n/2;
        q=q*q;
        c++;
    }
    printf("Power of %d is %d\n",a,p);
    return c;
}
int main()
{
    int c=power1(4,7);
    printf("No. of comparisons:%d\n",c);
    int d=power2(2,16);
    printf("No. of comparisons:%d\n",d);
}