#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct Node* next;
};
void createnode(struct node**head, int data)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
if(*head==NULL){
*head=temp;
return;
}
struct node*current=*head;
while(current->next!=NULL){
current = current->next;
}
current->next=temp;
}
void displaynodes(struct node*head)
{
struct node*current=head;
printf("Singly Linked List:");
while(current!=NULL)
{
printf("%d ->", current->data);
current=current->next;
}
printf("NULL\n");
}
int main()
{
struct node*head=NULL;
displaynodes(head);
createnode (&head, 10);
createnode (&head, 20);
createnode (&head, 30);
createnode (&head, 40);
displaynodes(head);
return 0;
}
