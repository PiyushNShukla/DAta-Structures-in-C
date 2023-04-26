#include<stdio.h>
#include<stdlib.h>
int n,a=1;
int **m,**s;
void matmulorder(int d[])
{
    int i,j,k,L,c;
    m=(int **)calloc(n+1,sizeof(int*));
    for( i=0;i<n+1;i++)
     m[i]=(int *)calloc(n+1,sizeof(int));
    s=(int **)calloc(n+1,sizeof(int*));
    for( i=0;i<n+1;i++)
     s[i]=(int *)calloc(n+1,sizeof(int));
    for(i=1;i<n+1;i++)
     m[i][i]=0;
    for(L=2;L<n+1;L++)
    {
        for(i=1;i<=n-L+1;i++)
        {
            j=i+L-1;
            m[i][j]=__INT_MAX__;
            for(k=i;k<j;k++)
            {
                c=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
                if(c<m[i][j])
                {
                    m[i][j]=c;
                    s[i][j]=k;
                }
            }
        }
    }
}
void parenthesis(int i,int j)
{
    if(i==j)
     printf("A%d ",a++);
    else{
        printf("(");
        parenthesis(i,s[i][j]);
        parenthesis(s[i][j]+1,j);
        printf(")");
    }
    
}
int main()
{
    int i,j;
    printf("Enter no. of matrices to be multiplied:");
    scanf("%d",&n);
    int *d=(int *)malloc(n+1*sizeof(int));
    printf("Enter the differnt dimensions of matrix:\n");
    for(i=0;i<n+1;i++)
     scanf("%d",&d[i]);
    matmulorder(d);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
         printf("%d ",m[i][j]);
        printf("\n"); 
    }
    printf("Minimum no. of multiplication required:%d\n",m[1][n]); 
    printf("Parenthsisisation:\n");
    parenthesis(1,n);
}