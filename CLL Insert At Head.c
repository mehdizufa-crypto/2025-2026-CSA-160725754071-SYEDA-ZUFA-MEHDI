//CLL Insert At Head
#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
void InsertAtHead(struct Node **head, struct Node **tail, int data){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
temp->data=data;
if(*head == NULL)
{
*head = *tail = temp;
temp->next= *head;
}
else
{
temp->next = *head;
*head=temp;
(*tail)->next= *head;
}
}
void displaynodes(struct Node*head)
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
InsertAtHead(&head,&tail,30);
InsertAtHead(&head,&tail,20);
InsertAtHead(&head,&tail,10);
displaynodes(head);
}
