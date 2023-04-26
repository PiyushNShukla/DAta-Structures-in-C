#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void InsertionSort(int a[],int n)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}
void display(int *arr,int n)
{
    
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");    
}
int main()
{
    int size,j,temp;
    printf("Enter size:");
    scanf("%d",&size);
    int *a;
    a=(int*)malloc(size*sizeof(int));
    srand(time(NULL));
    for (int i = 0; i <size; i++)
        a[i]=i+1;
    for (int i = 0; i <size; i++)
    {
        j=(rand()%(size-1))+1;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }   
    printf("Array before Sorting:\n");
    display(a,size);
    printf("Array after Sorting:\n");
    InsertionSort(a,size);
    display(a,size);
}
