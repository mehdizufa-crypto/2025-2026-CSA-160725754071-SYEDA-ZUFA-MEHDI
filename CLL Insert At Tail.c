#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node*next;
};
void insertAtEnd(struct Node**head, struct Node **tail, int data)
{
struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
temp->data = data;

    if(*head == NULL)
    {
        *head = temp;
        *tail = temp;
        temp->next = *head;
        return;
    }

    temp->next = *head;
    (*tail)->next = temp;
    *tail = temp;
}void displaynodes(struct Node*head)
{
struct Node*current=head;
printf("Circular Linked List:");
do
{
printf("%d->", current->data);
current=current->next;
}
while(current != head);
printf("(head)\n");
}
int main()
{
struct Node*head=NULL;
struct Node*tail=NULL;
insertAtEnd(&head,&tail,10);
insertAtEnd(&head,&tail,20);
insertAtEnd(&head,&tail,30);
insertAtEnd(&head,&tail,40);
displaynodes(head);
return 0;
}
