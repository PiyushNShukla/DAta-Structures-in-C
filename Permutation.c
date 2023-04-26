#include <stdio.h>
#include<stdlib.h>
void Swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void permute(int a[],int p,int r,FILE *fp)
{
    
    if(p==r)
    {
        for(int j=0;j<=r;j++)
            fprintf(fp,"%d ",a[j]);
        fprintf(fp,"\n");
        
        return; 
    }
    int i;
    for(i=p;i<=r;i++)
    {
        Swap((a+i),(a+p));
        permute(a,p+1,r,fp);
        Swap((a+i),(a+p));
    }
    

}
int main()
{
    int arr[4]={1,2,3,4};
    FILE *fp;
    fp=fopen("file1.txt","w");
    permute(arr,0,3,fp);
    fclose(fp);

}