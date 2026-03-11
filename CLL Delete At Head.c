#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void DeleteAtBeginning(struct node** head)
{
    if(*head == NULL){
        printf("List is empty, cannot delete\n");
        return;
    }

    struct node* temp = *head;

    // If only one node
    if((*head)->next == *head){
        free(temp);
        *head = NULL;
        return;
    }

    struct node* last = *head;

    while(last->next != *head){
        last = last->next;
    }

    *head = (*head)->next;
    last->next = *head;

    free(temp);
}

void Displaynodes(struct node* head)
{
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;

    printf("Circular Linked List: ");

    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("(head)\n");
}

int main()
{
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    struct node* n2 = (struct node*)malloc(sizeof(struct node));
    struct node* n3 = (struct node*)malloc(sizeof(struct node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = n1;   // Circular link

    struct node* head = n1;

    printf("Original List:\n");
    Displaynodes(head);

    DeleteAtBeginning(&head);

    printf("After deleting first node:\n");
    Displaynodes(head);

    return 0;
}
