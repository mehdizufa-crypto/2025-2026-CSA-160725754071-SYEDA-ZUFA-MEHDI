#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
};
void InsertAtPosition(struct node**head, int data, int position)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
if(position==1){
temp->next= *head;
*head= temp;
return;
}
struct node* current= *head;
for(int i = 1; current!= NULL&&i<position-1; i++){
current = current->next;
}
if(current==NULL){
printf("Position out of range!\n");
free(temp);
return;
}
temp->next = current->next;
current->next=temp;
}
void displaynodes(struct node*head)
{
struct node* current=head;
printf("Singly Linked List:");
while(current!= NULL){
printf("%d->", current->data);
current = current->next;
}
printf("NULL\n");
}
int main()
{
struct node* head = NULL;
InsertAtPosition (&head, 10, 1);
InsertAtPosition (&head, 20, 2);
InsertAtPosition (&head, 30, 3);
InsertAtPosition (&head, 25, 3);
InsertAtPosition (&head, 40, 5);
displaynodes(head);
return 0;
}
