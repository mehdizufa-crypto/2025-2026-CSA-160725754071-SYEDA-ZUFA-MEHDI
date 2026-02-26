#include <stdio.h>
#include <stdlib.h>

// Create Structure
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Define head, temp, current
struct Node *head = NULL;
struct Node *temp, *current;

// Insert at Beginning
void insertBegin(int x)
{
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev=NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev=temp;
        head = temp;
    }
}

// Insert at End
void insertEnd(int x)
{
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev=NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        temp->prev=current;
    }
}

// Insert at Specific Position
void insertPosition(int x, int position)
{
    int i = 0;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev=NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    if(position == 1)
    {
        temp->next = head;
        head->prev=temp;
        head = temp;
        return;
    }

    current = head;

    while(i < position-1 && current->next != NULL)
    {
        current = current->next;
        i++;
    }


    current->next=temp;
temp->prev=current;
temp->next=current->next->next;

}

// Delete at Beginning
void deleteBegin()
{
    if(head == NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        current = head;
        head = head->next;
        head->prev=NULL;
        free(current);
    }
}

// Delete at End
void deleteEnd()
{
    if(head == NULL)
    {
        printf("Nothing to delete\n");
    }
    else
    {
        current = head;

        if(current->next == NULL)
        {
            free(current);
            head = NULL;
            return;
        }

        while(current->next->next != NULL)
        {
            current = current->next;
        }


      current->next=temp;
    current->next=NULL;
	temp->prev=NULL;
    free (temp);
    }
}

// Delete at Specific Position
void deletePosition(int position)
{
    int i = 1;

    if(head == NULL)
    {
        printf("No nodes to delete\n");
    }
    else
    {
        if(position == 1)
        {
            temp = head;
            head = head->next;
            head->prev=NULL;
            free(temp);
            return;
        }

        current = head;

        while(i < position-1 && current->next != NULL)
        {
            current = current->next;
            i++;
        }

        if(current->next == NULL)
        {
            printf("Position out of range\n");
            return;
        }

      temp = current;// stops before position
      temp = temp->next;     // move to node to delete
        current->next = temp->next;
        temp->prev=current;
        free(temp);
    }
}

// Display SLL
void display()
{
    if(head == NULL)
    {
        printf("Nothing to print\n");
    }
    else
    {
        current = head;
        while(current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main
int main()
{
    int choice, x, pos;

    while(1)
    {
        printf("\n--- Double LINKED LIST ---\n");
        printf("1. Insert Begin\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Begin\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&x);
                insertBegin(x);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d",&x);
                insertEnd(x);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d%d",&x,&pos);
                insertPosition(x,pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d",&pos);
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);
        }
    }
}
