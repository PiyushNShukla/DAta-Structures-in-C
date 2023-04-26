#include<stdio.h>
#include<time.h>
int counter=0;
int fiborec(int n)
{
    ++counter;
    if (n == 1)
        return 0;
    else if(n==2)
        return 1;
    else        
        return fiborec(n - 1) + fiborec(n - 2);
}
int fiboiter(int n)
{
    int a=0,b=1,c,i,count=0;
    for(i=3;i<=n;i++)
    {
        ++count;
        c=a+b;
        a=b;
        b=c;
    }
    printf("Nth fibonacci no.:%d\n",c);
    return count;
} 
int main()
{
    int n,f1,f2;
    clock_t start1,start2,end1,end2;
    double timer,timei;
    printf("Enter n:");
    scanf("%d",&n);
    printf("For Recursive Case:\n");
    start1=clock();
    f1=fiborec(n);
    end1=clock();
    timer=((double)(end1-start1))/CLOCKS_PER_SEC;
    printf("Nth fibonacci no.:%d\nNo. of comparisons:%d\nTime taken:%lfs\n",f1,counter,timer);
    printf("For Iterative Case:\n");
    start2=clock();
    f2=fiboiter(n);
    end2=clock();
    timei=((double)(end2-start2))/CLOCKS_PER_SEC;
    printf("No. of comparisons:%d\nTime taken:%lfs\n",f2,timei);
}