#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;      // For Stack
struct node *front = NULL;    // For Queue
struct node *rear = NULL;     // For Queue


struct node* createNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}



void push(int value) {
    struct node *newnode = createNode(value);
    newnode->next = top;
    top = newnode;
    printf("%d pushed to Stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    printf("%d popped from Stack\n", temp->data);
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }
    struct node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



void enqueue(int value) {
    struct node *newnode = createNode(value);
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d enqueued to Queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    struct node *temp = front;
    front = front->next;

    if (front == NULL)    // If queue becomes empty
        rear = NULL;

    printf("%d dequeued from Queue\n", temp->data);
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main() {
    int choice, value;

    while (1) {
        printf("\n--- ganga ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}









