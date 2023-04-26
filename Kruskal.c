#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 30
typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;
edge_list elist;
edge_list spanlist;
void kruskalAlgo(int n,int **cost);
int find(int parent[], int vertexno);
void applyUnion(int parent[], int c1, int c2,int n);
void print();
void Swap(edge *a,edge *b)
{
  edge temp=*a;
  *a=*b;
  *b=temp;
}
void heapify(int n,int i)
{
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left<n && elist.data[left].w>elist.data[largest].w)
   largest=left;
  if(right<n && elist.data[right].w>elist.data[largest].w)
   largest=right;
  if(largest!=i)
  {
    Swap(&elist.data[i],&elist.data[largest]);
    heapify(n,largest);
  }  
}
void heapsort()
{
  int i;
  for(i=elist.n/2-1;i>=0;i--)
  {
    heapify(elist.n,i);
  }
  for(i=elist.n-1;i>=0;i--)
  {
    Swap(&elist.data[i],&elist.data[0]);
    heapify(i,0);
  }
}
void kruskalAlgo(int n,int **cost) {
  int parent[MAX], i, j, x, y;
  elist.n = 0;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {

      if (cost[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = cost[i][j];
        elist.n++;
      }
    }

  heapsort();
  for (i = 0; i < n; i++)
    parent[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    x = find(parent, elist.data[i].u);
    y = find(parent, elist.data[i].v);

    if (x != y) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(parent, x, y,n);
    }
  }
}
int find(int parent[], int x) {
  return (parent[x]);
}
void applyUnion(int parent[], int x, int y,int n) {
  int i;

  for (i = 0; i < n; i++)
    if (parent[i] == y)
      parent[i] = x;
}
/*void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}*/
void print() {
  int i, cost = 0;
  printf("Edged List of MST:\n");
  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}
int main()
{
    int i,j,n,src,s,dest,grb,weight;
    int **cost;
    FILE *fp;
    fp=fopen("KruskalInput.txt","r");
    fscanf(fp,"%d",&n);
    printf("%d\n",n);
    cost=(int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
        cost[i]=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp,"%d%d%d",&src,&dest,&weight);
            cost[src][dest]=weight;
        }
    }
    fclose(fp);
    printf("Weight List:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
  kruskalAlgo(n,cost);
  print();
}