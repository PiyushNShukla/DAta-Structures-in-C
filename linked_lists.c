#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *push(struct node *start,int);
struct node *pop(struct node *start,int);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int);
struct node *reverse(struct node *start);
int main()
{
  struct node *start=NULL;
  int n;
  start=push(start,10);
  start=push(start,20);
  start=push(start,30);
  display(start);
  start=reverse(start);
  display(start);
  search(start,30);
  count(start);
  start=pop(start,30);
  display(start);
  count(start);
  search(start,30);
  start=pop(start,10);
  display(start);
  count(start);
  start=pop(start,20);
  display(start);
  count(start);
}
struct node *push(struct node *start,int data)
{
  struct node *tmp,*p;
  if(start==NULL)
  {  
    tmp=(struct node *)malloc(sizeof(struct node));
  tmp->info=data;
  tmp->link=start;
  start=tmp;
  return start;
 }


else
{    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->link!=NULL)
      p=p->link;
    p->link=tmp;
    tmp->link=NULL;   
    return start;
}
}
void display(struct node *start)
{
    struct node *p;
    if(start==NULL)
     printf("List is empty\n");
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }  
    printf("\n");
}
struct node *pop(struct node *start,int data)
{
    struct node *tmp,*p;
    if(start==NULL){
        printf("List is empty\n");
        return start;
        }
    if(start->info==data)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }    
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==data)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return start;
        }
        p=p->link;
    }
    return start;
}
void count(struct node *start)
{
    int c=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        p=p->link;
        c++;
    }
    printf("Number of elements=%d\n",c);
}
void search(struct node *start,int data)
{
    int pos=1;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        if(p->info==data){
            printf("Element found at %d position\n",pos);
            return;
            }
        p=p->link;
        pos++;
         
    }
    printf("Eement not found\n");
}
struct node *reverse(struct node *start)
{
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;

    }
    start=prev;
    return start;
}