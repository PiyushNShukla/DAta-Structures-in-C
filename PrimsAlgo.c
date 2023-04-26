#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 10000

/*typedef struct node
{
    int vertex;
    int weight;
} Node;*/

typedef struct min_heap
{
    int vertex;
    int distance;
} MinHeap;

int heap_size = 0;

void swap(MinHeap *a, MinHeap *b)
{
    MinHeap temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap heap[], int idx)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if (left < heap_size && heap[left].distance < heap[smallest].distance)
    {
        smallest = left;
    }

    if (right < heap_size && heap[right].distance < heap[smallest].distance)
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        swap(&heap[idx], &heap[smallest]);
        heapify(heap, smallest);
    }
}

void insert(MinHeap heap[], int vertex, int distance)
{
    heap[heap_size].vertex = vertex;
    heap[heap_size].distance = distance;

    int current = heap_size;
    while (current > 0 && heap[current].distance < heap[(current - 1) / 2].distance)
    {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }

    heap_size++;
}

MinHeap extract_min(MinHeap heap[])
{
    MinHeap min = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    heapify(heap, 0);
    return min;
}

int is_empty()
{
    return (heap_size == 0);
}


void Adj_list(int *deg, int** adj_list, FILE *fp, int n){
    int i,j,garb,v1,v2,w;
    fscanf(fp,"%d",&garb);
    
    for(i=0;i<n;i++){
        for(j=0;j<deg[i];j++){
            fscanf(fp,"%d%d%d",&v1,&v2,&w);
            adj_list[i][j] = v2;
        }
    }
}

void PrimsMST(MinHeap heap[], int **adj_list,int *parent, int *visited,int *cost, int **weight, int *deg, int n ){

    int i;

    while(!is_empty()){
        MinHeap min = extract_min(heap);
        int u = min.vertex;
        visited[u] = 1;   
        for(i=0;i<deg[u];i++){
            int v = adj_list[u][i];
            //int d = heap[v].distance;
            if(!visited[v] && cost[v] > weight[u][v]  ){
                //implicit decrease key ?????
                cost[v] = weight[u][v];
                //heapify(heap, v);
                
                parent[v] = u;
                insert(heap,v,cost[v]);
            }
        }
    }
}

int main(void){

    int i,j,n,v1,v2,w,total=0;
    int garb;
    int *deg,*parent,*visited;
    int **adj_list, **weight;
    FILE *fp;

    fp = fopen("Gr.txt","r");
    fscanf(fp,"%d",&n);
    
    deg = (int*)calloc(n,sizeof(int));
    visited = (int*)calloc(n,sizeof(int));
    parent = (int*)calloc(n,sizeof(int));
    adj_list = (int**)malloc(n*sizeof(int*));

    weight = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)    weight[i] = (int*)calloc(n,sizeof(int));

    while( fscanf(fp,"%d%d%d",&v1,&v2,&w)!=EOF ){
        deg[v1]++;
        weight[v1][v2] = w;
    }

    for(i=0;i<n;i++)    adj_list[i] = (int*)calloc(deg[i],sizeof(int));
    
    rewind(fp);
    Adj_list(deg, adj_list, fp, n);
    fclose(fp);
    int *cost=(int*)calloc(n,sizeof(int));
    printf("Adjacency List\n");
    for(i=0;i<n;i++){
        for(j=0;j<deg[i];j++)   printf("%d\t",adj_list[i][j]);
        printf("\n");
    }

    int src = 0;

    MinHeap heap[MAX];

    for(i=0;i<n;i++){
        if(i==src)  insert( heap, src, 0);
        else    insert( heap, i, INT_MAX);
    }
    for(i=0;i<n;i++)
     cost[i]=INT_MAX;
    cost[src]=0;
    printf("\n");

    printf("Weight Matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)    printf("%d  ",weight[i][j]);
        printf("\n");
    }
    printf("\n");
    
    PrimsMST(heap, adj_list, parent, visited,cost,weight,deg,n);
    printf("Predecessor matrix:\n");
    for(i=0;i<n;i++)
     printf("%d ",parent[i]);
    printf("\n"); 
    printf("MST\n");
    for(i=1;i<n;i++){
        printf("%d -> %d = %d", i, parent[i], weight[i][parent[i]]);
        total+=weight[i][parent[i]];
        printf("\n");
    }
    printf("Total Cost:%d\n",total);
}