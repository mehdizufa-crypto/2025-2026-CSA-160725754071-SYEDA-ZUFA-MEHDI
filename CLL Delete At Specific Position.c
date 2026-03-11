#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

// Function to display circular list
void display(struct Node *head) {

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(head)\n");
}

// Function to delete at specific position in CLL
void deleteAtPosition(struct Node **head, int position) {

    if(*head == NULL) {
        printf("No nodes to delete\n");
        return;
    }

    struct Node *current = *head;

    // Delete first node
    if(position == 1) {

        // If only one node
        if(current->next == *head) {
            free(current);
            *head = NULL;
            return;
        }

        struct Node *last = *head;

        while(last->next != *head)
            last = last->next;

        struct Node *temp = *head;
        *head = (*head)->next;
        last->next = *head;

        free(temp);
        return;
    }

    int i = 1;

    while(i < position - 1 && current->next != *head) {
        current = current->next;
        i++;
    }

    if(current->next == *head) {
        printf("Position out of range\n");
        return;
    }

    struct Node *temp = current->next;
    current->next = temp->next;

    free(temp);
}

// Main function
int main() {

    // Creating circular list: 10->20->30->40->50
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n5 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = n4;

    n4->data = 40;
    n4->next = n5;

    n5->data = 50;
    n5->next = head;   // circular link

    printf("Original List:\n");
    display(head);

    int pos;
    printf("Enter the position in which you want to delete the node: ");
    scanf("%d", &pos);

    deleteAtPosition(&head, pos);

    printf("List after deletion:\n");
    display(head);

    return 0;
}
