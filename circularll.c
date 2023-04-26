#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int next;
}node;
node *last=NULL;
int length()
{
    struct node* temp;
    int c=0;
        temp = last->next;
        do {
            temp = temp->next;
            c++;
        }while (temp!=last->next);
    return c;   
    
}
void createList()
{
    if (last== NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            insertAtfront();
             for (int i = 2; i <= n; i++) {
                insertAtend();
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}
void display()
{
    if (last == NULL)
        printf("\nList is empty\n");
 
    // Else print the list
    else {
        struct node* temp;
        temp = last->next;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != last->next);
        printf("%d\n",temp->data);
    }
        
    }
void insertAtfront()
{
    int ele;
    node *tmp;
    printf("Enter an element:");
    scanf("%d",&ele);
    tmp=malloc(sizeof(struct node));
    tmp->data=ele;
    if(last==NULL){
        last=tmp;
        last->next=last;
    }
    else{
    tmp->next=last->next;
    last->next=tmp;}
}
void insertAtend()
{
    int ele;
    node *tmp;
    printf("Enter an element:");
    scanf("%d",&ele);
    tmp=malloc(sizeof(struct node));
    tmp->data=ele;
    tmp->next=last->next;
    last->next=tmp;
    last=tmp;
}
void insertAtpos()
{
    int pos,i=1,len,ele;
    len=length();
    printf("\nEnter position:");
    scanf("%d", &pos);
    if(pos<1 || pos>len+1)
        printf("Out of Bounds\n");
    else if(pos==1)
        insertAtfront();
    else if(pos==len+1)
        insertAtend();        
    else{
        printf("\nEnter an element:");
    scanf("%d", &ele);
        struct node *temp, *newnode;
        newnode = malloc(sizeof(struct node));
    temp = last->next;
    newnode->data =ele;
    // newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    }

}
void delFront()
{
   struct node* temp;
 
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    // Else last node now contains
    // reference of the second node
    // in the list because the
    // list is circular
    else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    } 
}
void delEnd()
{
    struct node* temp;
 
    // If list is empty
    if (last == NULL)
        printf("\nList is empty.\n");
 
    temp = last->next;
 
    // Traverse the list till
    // the second last node
    while (temp->next != last)
        temp = temp->next;
 
    // Second last node now contains
    // the reference of the first
    // node in the list
    temp->next = last->next;
    last = temp;
}
void delPos()
{
    int i = 1, pos;
    if (last == NULL)
        printf("\nList is empty\n");
     else {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        if(pos<1 || pos>length())
            printf("Out of Bounds\n");
        else if(pos==1)
            delFront();
        else if(pos==length())
            delEnd();
        else{ 
            struct node *temp, *position;           
        position = malloc(sizeof(struct node));
        temp = last->next;
  
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
  
        // Change Links
        position = temp->next;
        temp->next = position->next;
  
        // Free memory
        free(position);
    }
    }
}
void main()
{
     int choice;
    while (1) {

        printf("\n\t1 To create List\n");
        printf("\n\t2  To see list\n");
        printf("\t3  For insertion at"
               " starting\n");
        printf("\t4  For insertion at"
               " end\n");
        printf("\t5  For insertion at "
               "any position\n");
        printf("\t6  For deletion of "
               "first element\n");
        printf("\t7  For deletion of "
               "last element\n");
        printf("\t8  For deletion of "
               "element at any position\n");
        printf("\t9 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
            createList();
            break;
        case 2:
            display();
            break;
        case 3:
            insertAtfront();
            break;
        case 4:
            insertAtend();
            break;
        case 5:
           insertAtpos();
            break;
        case 6:
            delFront();
            break;
        case 7:
            delEnd();
 
            break;
        case 8:
            delPos();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
}