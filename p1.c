#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX - 1)
    {
        printf("\nStack Overflow! Cannot push %d\n", x);
    }
    else
    {
        top++;
        stack[top] = x;
        printf("\n%d pushed to stack\n", x);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow! Nothing to pop\n");
    }
    else
    {
        printf("\n%d popped from stack\n", stack[top]);
        top--;
    }
}


void display()
{
    int i;
    if(top == -1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        printf("\nStack Elements:\n");
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while(1)
    {printf("Name:Ganga\n");
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}
