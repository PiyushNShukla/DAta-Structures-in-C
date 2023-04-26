#include<stdio.h>
#include<stdlib.h>
int isSparse(int **arr,int m,int n)
{
    int c=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
                c++;
        }
    }
    return (c>(m*n)/2);
}
int main()
{
    int m,n,i,j;
    printf("Enter the dimensions:");
    scanf("%d%d",&m,&n);
    int** arr = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
        arr[i] = (int*)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (i = 0; i < m; i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    if(isSparse(arr,m,n))
    {
        printf("It is a sparse matrix.");
    }
    else{
        int size = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] != 0)
                size++;
 
    // number of columns in compactMatrix (size) must be
    // equal to number of non - zero elements in
    // sparseMatrix
    int compactMatrix[3][size];
 
    // Making of new matrix
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (arr[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = arr[i][j];
                k++;
            }
 
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<size; j++)
            printf("%d ", compactMatrix[i][j]);
 
        printf("\n");
    }
    }
}