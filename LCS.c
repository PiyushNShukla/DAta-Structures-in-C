#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
char b[N][N];
int **c;
void LCSlenghth(char X[],char Y[])
{
    int m,n,i,j;
    m=strlen(X);
    n=strlen(Y);
    //printf("%d %d\n",m,n);
    c=(int**)calloc(m+1,sizeof(int*));
    for(i=0;i<m+1;i++){
     c[i]=(int*)calloc(n+1,sizeof(int));
    
     }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
             {
                c[i][j]=1+c[i-1][j-1];
                b[i][j]='d';
             }
            else
            {
                if(c[i-1][j]>c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]='u';
                } 
                else if(c[i-1][j]==c[i][j-1])
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]='x';
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]='l';
                }
            }
        }
    } 
   
}
void printLCS(int i,int j,int len,char X[],char str[],int lcs_len)
{
    static int count=0;
    static char printedCheck[N*N][N]={0};
    if(i==0 || j==0)
    {
        if(len==-1){
            int k;
            for(k=0;k<count;k++)
            {
                if(strcmp(printedCheck[k],X)==0)
                 return;
            }
         printf("%s\n",X);
         strcpy(printedCheck[count],X);
         count++;
         
         }
        return;
    }
    if(b[i][j]=='x')
      {
        printLCS(i-1,j,len,X,str,lcs_len);
        printLCS(i,j-1,len,X,str,lcs_len);
      } 
    else if(b[i][j]=='u')
      printLCS(i-1,j,len,X,str,lcs_len);
    else if(b[i][j]=='l')
      printLCS(i,j-1,len,X,str,lcs_len);    
    else{
            X[len]=str[i-1];
            printLCS(i-1,j-1,len-1,X,str,lcs_len);
        }
}
int main()
{
    
    int m,n,i,j;
    char x[N],y[N];
    printf("Enter 1st string:");
    scanf("%s",x);
    printf("Enter 2nd string:");
    scanf("%s",y);
    m=strlen(x);
    n=strlen(y);
   // printf("%d %d\n",m,n);
    printf("%s\n",x);
    printf("%s\n",y);
    LCSlenghth(x,y);
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
         printf("%d ",c[i][j]);
        printf("\n"); 
    }
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
         printf("%c ",b[i][j]);
        printf("\n"); 
    }
    printf("Length of LCS:%d\n",c[m][n]);
    printf("LCS:\n");
    int length=c[m][n];
    char str[length];
    str[length]='\0';
    printLCS(m,n,length-1,str,x,length);
}
