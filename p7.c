#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;


void createlist(int value);
void insertleft(int key, int value);
void deletevalue(int value);
void display();

void createlist(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertleft(int key, int value) {
    if (head == NULL) return;

    struct node *temp = head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) return;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
}

void deletevalue(int value) {
    struct node *temp = head;

    while (temp && temp->data != value)
        temp = temp->next;

    if (!temp) return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct node *temp = head;
    printf("Doubly Linked List: ");

    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    printf("Name::Ganga\n");
    createlist(20);
    createlist(22);
    createlist(45);
    createlist(71);
    createlist(65);

    printf("Initial list:\n");
    display();

    printf("After insert value to left:\n");
    insertleft(20, 90);
    display();

    printf("After deleting 71:\n");
    deletevalue(71);
    display();

    return 0;
}


