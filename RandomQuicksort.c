#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int counter=0;
void R_Quicksort(int A[],int p,int r);
int Partition(int A[],int p,int r);
int R_Partition(int A[],int p,int r);
void printArray(int A[],int);
int fact(int x);
void permute(int a[],int p,int r,FILE *fp)
{
    fp=fopen("file1.txt","w");
    if(p==r)
    {
        for(int j=0;j<=r;j++)
            fprintf(fp,"%d ",a[j]);
        fprintf(fp,"\n");
        
        return; 
    }
    int i;
    for(i=p;i<=r;i++)
    {
        Swap((a+i),(a+p));
        permute(a,p+1,r,fp);
        Swap((a+i),(a+p));
    }
    
}
int fact(int x)
{
    if(x==0)
     return 1;
    else
     return x*fact(x-1); 
}
void Swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void R_Quicksort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=R_Partition(A,p,r);
        R_Quicksort(A,p,q-1);
        R_Quicksort(A,q+1,r);
    }
}
int Partition(int A[],int p,int r)
{
    ++counter;
   int pivot=A[p];
   int i=p;
   for(int j=p+1;j<=r;j++)
   {
    
    if(A[j]<=pivot)
    {
        
        i++;
        Swap(&A[i],&A[j]);
       // printArray(A,8);
    }
   }
    Swap(&A[p],&A[i]);
    //printArray(A,8);
    return i;
   
}
int R_Partition(int arr[], int low, int high)
{
    
    srand(time(NULL));
    int random = low + rand() % (high - low);
    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;
  
    return Partition(arr, low, high);
}
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    int i,j,k=1,f,sum=0,n;
    FILE *fp;
    printf("Enter size:");
    scanf("%d",&n);
    printf("Enter elements:\n");
    int *arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
    permute(arr,0,n-1,fp);
    
    f=fact(n);
    fp=fopen("file1.txt","r");
    for(int i=1;i<=f;i++)
    {
        for(j=0;j<n;j++)
            fscanf(fp,"%d",&arr[j]); 
        /*printf("Input array:\n%d)",k);
        printArray(arr,n);
        R_Quicksort(arr,0,n-1);
        printf("sorted Array:\n");
        printArray(arr,n);*/
        printf("No. of comparisons:%d\n",counter);
        k++;
        sum+=counter;
        counter=0;
        fscanf(fp,"\n");
    }
    printf("Average no. of comparisons:%d\n",sum/fact(n));
    fclose(fp);
}
