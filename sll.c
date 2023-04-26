#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
int length()
{
    struct node* temp;
    int c=0;
        temp = start;
        while (temp != NULL) {
            temp = temp->link;
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
            printf("%d ", temp->info);
            temp = temp->link;
        }
        printf("\n");
    }
}
void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
}  
void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}  

void insertAtPosition()
{
    int pos, data, i = 1,len;
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
    scanf("%d", &data);
        struct node *temp, *newnode;
        newnode = malloc(sizeof(struct node));
    temp = start;
    newnode->info = data;
    // newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
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
        start = start->link;
        free(temp);
    }
}
  
// Function to delete from the end
// of the linked list
void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
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
            struct node *temp, *position;           
        position = malloc(sizeof(struct node));
        temp = start;
  
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
  
        // Change Links
        position = temp->link;
        temp->link = position->link;
  
        // Free memory
        free(position);
    }
    }
}
  

  
// Function to reverse the linked list
void reverseLL()
{
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
  
    // If LL is empty
    if (start == NULL)
        printf("List is empty\n");
  
    // Else
    else {
  
        // Traverse the LL
        while (start != NULL) {
  
            // reversing of points
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
  
        // New head Node
        temp = start;
  
        printf("Reversed linked "
               "list is : ");
  
        // Print the LL
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }
}
void max()
{
    struct node *max,*ptr;
    max=start;
    if (start == NULL)
        printf("\nList is empty\n"); 
    else {
        ptr = start;
         while (ptr != NULL) {
           if(max->info>ptr->info)
            max=ptr;
           ptr=ptr->link; 
        }
    }
    printf("Min ele=%d",max->info);
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
        printf("\t10 To max\n");
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
            reverseLL();
            break;
        case 10:
            max();
            break;
        default:
           exit(1);
        }
    }
    return 0;
}