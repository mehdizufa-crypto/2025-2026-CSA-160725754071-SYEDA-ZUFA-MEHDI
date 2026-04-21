//DEQueue using Arrays
#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Insert at front
void insertFront(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = x;
}

// Insert at rear
void insertRear(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

// Delete from front
void deleteFront() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Display Deque
void display() {
    int i;

    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", deque[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%d ", deque[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", deque[i]);
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
