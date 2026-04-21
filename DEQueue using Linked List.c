//DEQueue using Linked List
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Insert at front
void insertFront(int x) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;

    if (front == NULL) {
        front = rear = temp;
    } else {
        front->prev = temp;
        front = temp;
    }
}

// Insert at rear
void insertRear(int x) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted element: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

// Delete from rear
void deleteRear() {
    if (rear == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node *temp = rear;
    printf("Deleted element: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
}

// Display elements
void display() {
    struct Node *temp = front;

    if (temp == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, x;

    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertFront(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insertRear(x);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
