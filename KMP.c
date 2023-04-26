#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* prefix(char p[])
{
    int m=strlen(p);
    int* pi=(int*)calloc(m,sizeof(int));
    //int pi[m];
    pi[0]=0;
    int i=1,j=0;
    while(i<m)
    {
        if(p[j]==p[i]){
         j++;
         pi[i] =j; 
         i++;
         }
        else{
            if(j!=0)
             j=pi[j-1];
            else{
                pi[i]=0;
                i++;
            } 
        } 
    }
    return pi;
}
void kmpmatcher(char t[],char p[])
{
    int m,n,i=0,j=0;
    int *pr;
    m=strlen(p);
    n=strlen(t);
    pr=prefix(p);
    while (i < n) {
      if (p[j] == t[i]) {
         j++;
         i++;
      }
      if (j == m) {
         printf("Found pattern at index %d\n",i - j);
         j = pr[j - 1];
      }
      else if (i < n && p[j] != t[i]) {
         if (j != 0)
         j = pr[j - 1];
         else
         i = i + 1;
      }
   }
}
int main()
{
    char t[50],p[50];
    int m,n;
    printf("Enter the text:");
    scanf("%s",t);
    printf("Enter the pattern to be searched:");
    scanf("%s",p);
    kmpmatcher(t,p);
}