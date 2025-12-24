#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    queue[++rear] = item;
    printf("Inserted %d\n", item);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
            printf("Name:Ganga\n");
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid Choice!\n");
        }
    }
}
