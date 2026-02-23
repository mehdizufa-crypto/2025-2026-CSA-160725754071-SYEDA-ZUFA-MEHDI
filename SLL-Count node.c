//count nodes
#include <stdio.h>
#include <stdlib.h>
// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};
// Function to count the number of nodes in SLL
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head; // Start from head
    while (temp != NULL) {
        count++;
        temp = temp->next; // Move to next node
    }
    return count;
}
// Function to display the SLL
void displayNodes(struct Node* head) {
    struct Node* current = head;
    printf("Singly Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }     printf("NULL\n"); }
// Main function
int main() {
    struct Node* head = NULL;
    struct Node* temp;
    struct Node* current;
    // Manually creating and linking nodes
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 10;
    temp->next = NULL;
    head = temp; // First node
    current = temp; // Point to first node
    // Creating second node
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 20;
    temp->next = NULL;
    current->next = temp;
    current = temp;
    // Creating third node
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 30;
    temp->next = NULL;
    current->next = temp;
    // Display the linked list
    printf("Original List:\n");
    displayNodes(head);
    // Count the number of nodes
    printf("Number of nodes in the list: %d\n", countNodes(head));
    return 0;
}
