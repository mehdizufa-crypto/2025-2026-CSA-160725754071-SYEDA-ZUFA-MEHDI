#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;


void enqueue(int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = NULL;

    if (head == NULL && tail == NULL) {
        head = tail = temp;
        tail->next = head;
    }
    else {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }

    printf("%d inserted\n", value);
}


void dequeue() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = head;


    if (head == tail) {
        printf("%d deleted\n", temp->data);
        head = tail = NULL;
        free(temp);
    }
    else {
        printf("%d deleted\n", temp->data);
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void display() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *current = head;

    printf("Queue: ");


    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}


int main() {


    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();


    dequeue();
    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
