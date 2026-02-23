//delete at specific position
#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

// Function to display the list
void display(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete at specific position
void deleteAtPosition(struct Node **head, int position) {

    // Step 1: Check if head == NULL
    if(*head == NULL) {
        printf("No nodes to delete\n");
        return;
    }

    struct Node *current = *head; // Step 4
    int i = 1;

    // Special case: delete first node
    if(position == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Step 7: Traverse till position-1
    while(i < position - 1 && current->next != NULL) {
        current = current->next;
        i++;
    }

    // If position is invalid
    if(current->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    // Step 8: temp = current
    struct Node *temp = current;

    // Step 9: temp = temp->next
    temp = temp->next;

    // Step 10: current->next = temp->next
    current->next = temp->next;

    // Step 11: free(temp)
    free(temp);
}

// Main Function
int main() {

    // Already existing list: 10->20->30->40->50
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 50;
    head->next->next->next->next->next = NULL;

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
