#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int counter=0;
int ch2;
void Quicksort(int A[],int p,int r);
int Partition(int A[],int p,int r);
void printArray(int A[],int n);
int switchPartition(int A[],int p,int r,int ch2);
void Swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void Quicksort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=switchPartition(A,p,r,ch2);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}
int Partition(int A[],int p,int r)
{
   int pivot=A[p];
   int i=p;
   for(int j=p+1;j<=r;j++)
   {
    ++counter;
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
int switchPartition(int A[],int p,int r,int ch2)
{
    switch(ch2)
    {
        case 1:
        break;
        case 2:
        Swap(&A[p],&A[r]);
        break;
        case 3:
        Swap(&A[(p+r)/2],&A[p]);
        break;
        default:
        printf("Wrong Choice!");
    }
    return Partition(A,p,r);
}
void printArray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    FILE *fp;
    int ch1,i,n;
    printf("Enter size of file:");
    scanf("%d",&n);
    srand(time(NULL));
    int *arr=(int*)malloc(sizeof(int)*n);
    int *a1=(int*)malloc(sizeof(int)*n);
    /*for(i=0;i<n;i++)
     a1[i]=(rand()%n)+1;
    printArray(a1,n);*/ 
    while(1)
    {
        printf("1.Ascending\n2.Descending\n3.Random\nExit\nEnter your choice:");
        scanf("%d",&ch1);
        switch (ch1)
        {
        case 1:
        fp=fopen("Quick.txt","w");
        if(fp==NULL)
         printf("L File");
        for(int i=0;i<n;i++)
         fprintf(fp,"%d ",i+1);
        printf("1.Beginning\n2.End\n3.Middle\nEnter choice:");
        scanf("%d",&ch2);
        fclose(fp);     
        break;
        case 2:
        fp=fopen("Quick.txt","w");
        if(fp==NULL)
         printf("L File");
        for(int i=0;i<n;i++)
         fprintf(fp,"%d ",n-i);
        printf("1.Beginning\n2.End\n3.Middle\nEnter choice:");
        scanf("%d",&ch2);
        fclose(fp);
        break;
        case 3:
        fp=fopen("Quick.txt","w");
        if(fp==NULL)
         printf("L File");
        for(int i=0;i<n;i++)
         fprintf(fp,"%d ",rand()%n);
       // fprintf(fp,"%d ",&a1); 
        printf("1.Beginning\n2.End\n3.Middle\nEnter choice:");
        scanf("%d",&ch2);
        fclose(fp);
        break;
        case 4:
        exit(0);
        default:
        printf("Wrong choice!");
        break;
        }
        fp=fopen("Quick.txt","r");
        for(int i=0;i<n;i++)
        {
            fscanf(fp,"%d ",&arr[i]);
        }
        Quicksort(arr,0,n-1);
        printf("NO. of comparisons:%d\n",counter);
        counter=0;
        fclose(fp);
    }
    /*int a[10]={10,9,8,7,6,5,4,3,2,1};
    Quicksort(a,0,9);
    printf("NO. of comparisons:%d\n",counter);*/
    return 0;
}
