#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node from the end of CLL
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;

    // If only one node
    if (current->next == *head) {
        free(current);
        *head = NULL;
        return;
    }

    // Traverse to second last node
    while (current->next->next != *head) {
        current = current->next;
    }

    struct Node* temp = current->next; // last node
    current->next = *head; // link back to head
    free(temp);
}

// Function to display nodes
void displayNodes(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(head)\n");
}

// Main function
int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = temp;

    temp->data = 20;
    temp->next = current;

    current->data = 30;
    current->next = head;   // circular link

    printf("Original List:\n");
    displayNodes(head);

    deleteAtEnd(&head);
    printf("After deleting node at the end:\n");
    displayNodes(head);

    deleteAtEnd(&head);
    printf("After deleting another node at the end:\n");
    displayNodes(head);

    deleteAtEnd(&head);
    printf("After deleting the last node:\n");
    displayNodes(head);

    return 0;
}
