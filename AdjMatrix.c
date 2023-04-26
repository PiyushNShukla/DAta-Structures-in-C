#include<stdio.h>
#include<stdlib.h>
int e,v;
void createAdjmat(int Adj[][v+1],int arr[][2])
{
  for(int i=0;i<e;i++)
  {
    int x=arr[i][0];
    int y=arr[i][1];
    Adj[x][y]=1;
    Adj[y][x]=1;
  }
}
void printArray(int A[][v+1])
{
     for (int i = 1; i < v+1; i++) {
        for (int j = 1; j < v+1; j++) {          
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter no. of vertices:");
    scanf("%d",&v);
    printf("Enter no. of edges:");
    scanf("%d",&e);
    int arr[e][2];
    int Adj[v+1][v+1];
     for (int i = 0; i < v + 1; i++) {
  
        for (int j = 0; j < v + 1; j++) {
            Adj[i][j] = 0;
        }
    }    
    for(int i=0;i<e;i++)
    {
        printf("enter pair of vertices that contain an edge:");
        for(int j=0;j<2;j++)
            scanf("%d",&arr[i][j]);
    }
    createAdjmat(Adj,arr);
    printArray(Adj);

}