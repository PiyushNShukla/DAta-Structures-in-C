#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 100
int Queue[MAX_VERTICES];
int Rear = - 1;
int Front = - 1;
int isEmpty()
{
    return((Front==-1 || Front>Rear));
}
int isFull()
{
    return((Rear==MAX_VERTICES-1));
}
void enqueue(int n)
{
   
   if (Front == - 1)
    Front = 0;
   Queue[++Rear]=n;
} 
int dequeue()
{
    if (!isEmpty())
    {
        int item;
        item=Queue[Front++];
        return item;
    }
} 

void bfs(int **graph,int n,int src,int *deg)
{
    int i,j;
    int *visited=calloc(n,sizeof(int));
    visited[src]=1;
    enqueue(src);
    while(!isEmpty())
    {
        int vertex=dequeue();
        printf("vertex %d is discovered\n",vertex);
        for(i=0;i<deg[vertex];i++)
        {
            j=graph[vertex][i];
            if(visited[j]==0)
            {
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}
int main()
{
    int i,j,n,src,s,dest,grb;
    int *deg,**adjList;
    FILE *fp;
    fp=fopen("Gr.txt","r");
    fscanf(fp,"%d",&n);
   // printf("%d",n);
    adjList=(int**)malloc(n*sizeof(int*));
    deg=(int*)calloc(n,sizeof(int));
    while(fscanf(fp,"%d%d",&src,&dest)!=EOF)
    {
        deg[src]++;
    }
    for(i=0;i<n;i++)
        adjList[i]=(int*)calloc(deg[i],sizeof(int));
    rewind(fp);
    fscanf(fp,"%d",&grb);
    for(i=0;i<n;i++)
    {
        for(j=0;j<deg[i];j++)
        {
            fscanf(fp,"%d%d",&src,&dest);
            //printf("%d %d\n",src,dest);
            adjList[i][j]=dest;
        }
    }
    fclose(fp);
    printf("Adjacency List:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<deg[i];j++)
        {
            printf("%d ",adjList[i][j]);
        }
        printf("\n");
    }
    printf("Enter source vertex:");
    scanf("%d",&s);
    bfs(adjList,n,s,deg);
}