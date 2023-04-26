#include<stdio.h>
#include<stdlib.h>
int c=0;
void Swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
void heapify(int A[],int n,int i)
{
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left<n && A[left]>A[largest])
  {
   largest=left;
   c++;
   }
  if(right<n && A[right]>A[largest])
   {largest=right;
    c++;
   }
  if(largest!=i)
  {
    c++;
    Swap(&A[i],&A[largest]);
    heapify(A,n,largest);
  }  
}
void heapsort(int A[],int n)
{
  int i;
  for(i=n/2-1;i>=0;i--)
  {
    heapify(A,n,i);
  }
  for(i=n-1;i>=0;i--)
  {
    Swap(&A[i],&A[0]);
    heapify(A,i,0);
  }
}
void display(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    int A[5]={54,6,12,88,42};
    printf("Before Sorting:\n");
    display(A,5);
    heapsort(A,5);
    printf("After Sorting:\n");
    display(A,5);
    printf("%d\n",c);
}