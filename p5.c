#include<stdio.h>
#include<stdlib.h>

 struct node
 {
     int data;
     struct node*next;

 };struct node*head=NULL;

 struct node*create(int value)
 {
     struct node*temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=value;
     temp->next=NULL;
     return temp;
 };

 void insert_at_begin(int value)
 {
     struct node*newnode;
     newnode=create(value);
     if(head==NULL)
     {
         head=newnode;
     }
     else
     {
         newnode->next=head;
         head=newnode;
     }
 }

 void delete_at_first()
 {
     struct node*temp;
     if(head==NULL)
     {
         printf("deletion not possible");
         return;
     }
     else
     {
         temp=head;
         head=temp->next;
         free(temp);
     }
 }


 void delete_at_end()
 {
     struct node*temp1,*temp2;
     if(head==NULL)
     {
         printf("deletion not possible");
         return;
     }
     else
     {
         temp1=head;
         while(temp1->next!=NULL)
         {
             temp2=temp1;
             temp1=temp1->next;
         }
         temp2->next=NULL;
         free(temp1);
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




void delete_spec_value(int key)
{
if (head == NULL)

{
printf("List is empty. Cannot delete.\n");
return;
}
struct node *temp1 = head;
struct node *temp2 = NULL;

if (temp1 != NULL && temp1->data == key)
{
head = temp1->next;
free(temp1);
printf("Element %d deleted.\n", key);
return;
}

while (temp1 != NULL && temp1->data != key)
{
temp2 = temp1;
temp1 = temp1->next;
}

if (temp1 == NULL)
{
printf("Element %d not found in the list.\n", key);
return;
}

temp2->next = temp1 ->next;
free(temp1);
printf("Element %d deleted.\n", key);
}
void display()
{
struct node *temp;
if(head==NULL)

{
printf("list is empty");
}
else
{
temp=head;
while(temp->next!=NULL)
{
printf("%d-> ", temp->data);
temp=temp->next;
}
printf("%d", temp->data);
}
}




    int main()
    {
        insert_at_begin(10);
        insert_at_begin(20);
        insert_at_begin(30);
        insert_at_begin(40);
        insert_at_begin(50);

        delete_at_first();
        delete_at_end();
        delete_spec_value(30);
        display();
    }
