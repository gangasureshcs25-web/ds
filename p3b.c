#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert()
{
    int item;
    if ((front == 0 && rear == SIZE-1) || (front == rear+1))
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1)
        front = rear = 0;
    else if (rear == SIZE-1)
        rear = 0;
    else
        rear++;

    queue[rear] = item;
    printf("Inserted: %d\n", item);
}

void delete()
{
    if (front == -1)
    {
        printf("\nQueue Empty!\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == SIZE-1)
        front = 0;
    else
        front++;
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue Empty!\n");
        return;
    }

    int i = front;
    printf("\nCircular Queue elements: ");

    if (front <= rear)
    {
        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
    }
    else
    {
        while (i < SIZE)
        {
            printf("%d ", queue[i]);
            i++;
        }
        i = 0;
        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {printf("\n Name:Ganga\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
