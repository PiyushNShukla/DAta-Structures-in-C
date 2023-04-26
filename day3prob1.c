#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *start=NULL;
void push(int ele)
{
    node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=ele;
    if(start==NULL)
    {
        temp->next=NULL;
        start=temp;
    }
    else{
        node *p;
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->next=NULL;
    }
}
int length(){
    node* temp;
    int c=0;
        temp = start;
        while (temp != NULL) {
            temp = temp->next;
            c++;
        }
    return c;  
}
void fromlast(int N)
{
    if(N>length())
        printf("Wrong input");
    else{
        node *p;
        int i=1;
        p=start;
        for (i = 1; i < length() - N + 1; i++)
            p = p->next;
        printf("%d", p->data);
        
    }
}
void display()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n"); 
    else {
        temp = start;
        printf("List is:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();
    fromlast(5);
}