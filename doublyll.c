#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
};
struct node* start = NULL;
int length()
{
    struct node* temp;
    int c=0;
        temp = start;
        while (temp != NULL) {
            temp = temp->next;
            c++;
        }
    return c;   
    
}
void createList()
{
   if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            insertAtFront();
             for (int i = 2; i <= n; i++) {
                insertAtEnd();
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
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
void insertAtFront()
{
    int ele;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &ele);
    temp->data = ele;
    if(start==NULL)
    {
        temp->next=NULL;
        temp->next=NULL;
        start=temp;
    }
    else{
    temp->prev=NULL;
    temp->next= start;
    start->prev=temp;  
    start = temp;
    }
}  
void insertAtEnd()
{
    int ele;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &ele);
    temp->data = ele;
    head = start;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
    temp->prev=head;
    temp->next=NULL;
}  

void insertAtPosition()
{
    int pos, ele, i = 1,len;
    len=length();
    printf("\nEnter position:");
    scanf("%d", &pos);
    if(pos<1 || pos>len+1)
        printf("Out of Bounds\n");
    else if(pos==1)
        insertAtFront();
    else if(pos==len+1)
        insertAtEnd();        
    else{
        printf("\nEnter number to be inserted:");
    scanf("%d", &ele);
        struct node *temp, *p;
        temp = malloc(sizeof(struct node));
    p = start;
    temp->data =ele;
    // newnode->link = 0;
    while (i < pos - 1) {
        p = p->next;
        i++;
    }
    temp->next = p->next;
    temp->prev = p;
    p->next=temp;
    p->next->prev=temp;
    }
}
  
// Function to delete from the front
// of the linked list
void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        start->prev=NULL;
        free(temp);
    }
}
  
// Function to delete from the end
// of the linked list
void deleteEnd()
{
    struct node *p, *temp;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        p = start;
        while (p->next
         != NULL) {
            p=p->next;
        }
        p->prev->next=NULL;
        free(p);
        }
}
  
// Function to delete from any specified
// position from the linked list
void deletePosition()
{
    int i = 1, pos;
    if (start == NULL)
        printf("\nList is empty\n");
     else {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        if(pos<1 || pos>length())
            printf("Out of Bounds\n");
        else if(pos==1)
            deleteFirst();
        else if(pos==length())
            deleteEnd();
        else{ 
            struct node *temp;           
                temp = start->next;
  
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
  
        // Change Links
       temp->prev->next=temp->next;
       temp->next->prev=temp->prev;
       free(temp);
    }
    }
}
  

  
// Function to reverse the linked list
void reverseLL(struct node **h)
{
    struct node* temp = NULL;
    struct node* current = *h;
 
    /* swap next and prev for all nodes of
      doubly linked list */
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if (temp != NULL)
        *h = temp->prev;
}

  
// Driver Code
int main()
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
        printf("\t9 To reverse the "
               "linked list\n");
        printf("\t10 To exit\n");
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
            insertAtFront();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            insertAtPosition();
            break;
        case 6:
            deleteFirst();
            break;
        case 7:
            deleteEnd();
 
            break;
        case 8:
            deletePosition();
            break;
        case 9:
            reverseLL(&start);
            break;
        case 10:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}