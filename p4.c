#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};*head=NULL;

struct node*create(int value)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct   node));
    temp->data=value;
    temp->next=NULL;
    return temp;
};

void insert_at_begin(int value)
{
    struct node*newnode;
    newnode=create(value);
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void insert_at_end(int value)
{
    struct node*newnode,*temp;
    newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insert_at_position(int value,int pos)
{
    struct node*newnode,*temp1,*temp2;
    int i,c=1;
    newnode=create(value);
    i=count();
    if(pos==1)
    {
        insert_at_begin(value);
    }
    else if (pos>i+1)
    {
        printf("insertion is not possible");
        return;
    }
    else
    {
        temp2=head;
        while(c<=pos-1 && temp1!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
            c++;
        }
        newnode->next=temp2->next;
        temp2->next=newnode;
    }
}


int count()
{
    struct node*temp;
    int i=1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return(i);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_begin(5);
    insert_at_position(15, 3);
    display();

    printf("Total nodes = %d\n", count());
    return 0;
}


