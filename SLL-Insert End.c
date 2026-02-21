#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node*next;
};
void insertAtEnd(struct Node**head,int data)
{
struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
temp->data=data;
temp->next=NULL;
if(*head==NULL)
{
*head=temp;
return;
}
struct Node*current= *head;
while(current->next!=NULL)
{
current=current->next;
}
current->next=temp;
}
void displayNodes(struct Node*head)
{
struct Node*current = head;
printf("Singly Linked List:");
while(current!=NULL)
{
printf("%d->", current->data);
current=current->next;}
printf("NULL\n");
}
int main()
{
struct Node*head=NULL;
insertAtEnd(&head,10);
insertAtEnd(&head,20);
insertAtEnd(&head,30);
insertAtEnd(&head,40);
displayNodes(head);
return 0;
}
