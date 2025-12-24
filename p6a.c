#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;


struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct node **head, int value) {
    struct node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sortList(struct node **head) {
    if (*head == NULL) return;

    struct node *i, *j;
    int temp;

    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


void reverseList(struct node **head) {
    struct node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}


void concatenate(struct node **head1, struct node **head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    struct node *temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head2;
    *head2 = NULL;
}

int main() {
    int choice, value;

    while (1) {
        printf("Name:Ganga\n");
        printf("\n---- MENU ----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 into List 1\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head2, value);
                break;

            case 3:
                printf("List 1: ");
                display(head1);
                break;

            case 4:
                printf("List 2: ");
                display(head2);
                break;

            case 5:
                sortList(&head1);
                printf("List 1 Sorted.\n");
                break;

            case 6:
                reverseList(&head1);
                printf("List 1 Reversed.\n");
                break;

            case 7:
                concatenate(&head1, &head2);
                printf("Concatenated List 2→List 1.\n");
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
