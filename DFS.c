#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 100
void dfs(int **graph,int n,int *deg)
{
    int i,j;
    int *visited=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        if(!visited[i])
            dfs_visit(graph,n,deg,visited,i);
    }
}
void dfs_visit(int **graph,int n,int *deg,int *visited,int src)
{
    visited[src]=1;
    
    for(int i=0;i<deg[src];i++)
    {
        int k=graph[src][i];
        if(!visited[k])
          dfs_visit(graph,n,deg,visited,k);
    }
    visited[src]=2;
    if(visited[src]==2)
     printf("%d->",src);
}
/*void bfs(int **graph,int n,int src,int *deg)
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
}*/
int main()
{
    int i,j,n,src,s,dest,grb;
    int *deg,**adjList;
    FILE *fp;
    fp=fopen("DFSInput.txt","r");
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
    dfs(adjList,n,deg);
}