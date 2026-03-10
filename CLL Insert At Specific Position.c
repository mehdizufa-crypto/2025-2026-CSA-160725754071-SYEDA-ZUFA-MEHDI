#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void InsertAtPosition(struct node **head, int data, int position)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    // Case 1: Insert at beginning
    if(position == 1)
    {
        if(*head == NULL)
        {
            *head = temp;
            temp->next = *head; // circular link
            return;
        }

        struct node *last = *head;
        while(last->next != *head)
        {
            last = last->next;
        }

        temp->next = *head;
        last->next = temp;
        *head = temp;
        return;
    }

    struct node *current = *head;

    for(int i = 1; current->next != *head && i < position-1; i++)
    {
        current = current->next;
    }

    if(current->next == *head && position > 2)
    {
        // inserting at end
        temp->next = *head;
        current->next = temp;
    }
    else
    {
        temp->next = current->next;
        current->next = temp;
    }
}

void displaynodes(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;

    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    while(current != head);

    printf("(head)\n");
}

int main()
{
    struct node* head = NULL;

    InsertAtPosition(&head, 10, 1);
    InsertAtPosition(&head, 20, 2);
    InsertAtPosition(&head, 30, 3);
    InsertAtPosition(&head, 25, 3);
    InsertAtPosition(&head, 40, 5);

    displaynodes(head);

    return 0;
}
