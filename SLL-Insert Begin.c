#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node*next;
};
void insertAtBeginning(struct Node**head, int data)
{
struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
temp->data = data;
temp->next = *head;
*head=temp;
}
void displaynodes(struct Node*head)
{
struct Node*current=head;
printf("Singly Linked List:");
while(current!=NULL)
{
printf("%d->", current->data);
current=current->next;
}
printf("NULL\n");
}
int main()
{
struct Node*head=NULL;
insertAtBeginning(&head,30);
insertAtBeginning(&head,20);
insertAtBeginning(&head,10);
displaynodes(head);
}

