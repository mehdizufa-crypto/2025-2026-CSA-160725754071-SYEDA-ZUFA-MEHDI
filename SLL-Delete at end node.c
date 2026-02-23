//delete at end
#include <stdio.h>
#include <stdlib.h>
// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};
// Function to delete a node from the end of SLL
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {  // If list is empty
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* current = *head;
    // If only one node is present
    if (current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }
    // Traverse to the second last node
    while (current->next->next != NULL) {
        current = current->next;
    }
struct Node* temp = current->next; // Store last node in temp
    current->next = NULL; // Remove last node
    free(temp); // Free memory of last node
}
// Function to display the nodes
void displayNodes(struct Node* head) {
    struct Node* current = head;
    printf("Singly Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
// Main function
int main() {
    // Predefined list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = temp;
    temp->data = 20;
    temp->next = current;
   current->data = 30;
    current->next = NULL;
    printf("Original List:\n");
    displayNodes(head);

    // Delete a node from the end
    deleteAtEnd(&head);
    printf("After deleting node at the end:\n");
    displayNodes(head);
    // Delete another node
    deleteAtEnd(&head);
    printf("After deleting another node at the end:\n");
    displayNodes(head);
    // Delete the last remaining node
    deleteAtEnd(&head);
    printf("After deleting the last node:\n");
    displayNodes(head);
    return 0;
}
