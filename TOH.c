#include<stdio.h>
#include<time.h>
int towerOfHanoi(int n, char a, char b, char c)
{
    int count=0;
    if(n>0)
    {
        count=towerOfHanoi(n - 1, a, c, b);
        printf("Move top disk from tower %c to the top of tower %c\n ",a,b);
        count++;
        count+=towerOfHanoi(n - 1, c,b,a);
    }
    return count;
    
}
 
// Driver code
int main()
{
    int N,c;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter value of N:");
    scanf("%d",&N);
    // A, B and C are names of rods
     start = clock();
    c=towerOfHanoi(N, 'A', 'B', 'C');
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("No. of moves:%d\n",c);
    printf("Time taken:%fs",cpu_time_used);
    return 0;
}