#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
void DeleteAtBeginning(struct node**head){
if(*head == NULL){
printf("List is empty, cannot delete\n");
return;
}
struct node* temp = *head;
*head = (*head)->next;
free(temp);
}
void Displaynodes(struct node*head)
{
struct node* temp = head;
printf("Linked List:");
while(temp!= NULL){
printf("%d->", temp->data);
temp=temp->next;}
printf("NULL\n");
}
int main()
{
struct node* n1= (struct node*)malloc(sizeof(struct node));
struct node* n2= (struct node*)malloc(sizeof(struct node));
struct node* n3= (struct node*)malloc(sizeof(struct node));
n1->data = 10;
n2->data = 20;
n3->data = 30;
n1->next = n2;
n2->next = n3;
n3->next = NULL;
struct node* head = n1;
printf("Original List:\n");
Displaynodes(head);
DeleteAtBeginning(&head);
printf("After deleting first node:\n");
Displaynodes(head);
return 0;
}
