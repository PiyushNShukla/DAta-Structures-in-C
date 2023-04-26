#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *top=NULL;
int isEmpty();
void push(int);
int pop();
int display();
int main()
{
    int ch,ele;
    while(1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Quit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        printf("Enter the element to be pushed:");
        scanf("%d",&ele);
        push(ele);
        break;
        case 2:
        printf("Popped element is:%d\n",pop());
        break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        default:
        printf("Wrong Choice!\n");
        break;
        }
    }
    return 0;
}
int isEmpty()
{return(top==NULL);}
void push(int ele)
{
    struct node* tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
       tmp->data=ele;
       tmp->next=top;
       top=tmp;
    }
}
int pop()
{
    struct node *tmp;
    int ele;
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    tmp=top;
    ele=tmp->data;
    top=top->next;
    free(tmp);
    return ele; 
}
int display()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else{
        struct node* temp;
         temp = top;
        printf("List is:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        
    }
}