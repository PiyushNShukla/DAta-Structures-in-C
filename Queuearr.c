#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int front = -1;
int rear = -1;
int isEmpty()
{
    return ((front == -1 || front == rear + 1));
}
int isFull(int n)
{
    return ((rear == n - 1));
}

void Enque(int n, int queue[])
{
    int ele;
    if (isFull(n))
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the element to be inserted:");
    scanf("%d", &ele);
    if (isEmpty())
        front = 0;
    queue[++rear] = ele;
}
int Deque(int queue[])
{
    int item;
    if (isEmpty())
    {
        printf("Queue Underflowflow\n");
        exit(1);
    }
    else
    {
        item = queue[front++];
        return item;
    }
}
void display(int queue[])
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main()
{
    int ch, size;
    printf("Enter size:");
    scanf("%d", &size);
    int *queue = (int *)malloc(sizeof(int));
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Quit\n");
        printf("Enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Enque(size, queue);
            break;
        case 2:
            printf("Deleted element is:%d\n", Deque(queue));
            break;
        case 3:
            display(queue);
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