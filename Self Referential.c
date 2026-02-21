#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
int main()
{
struct node *n1, *n2, *n3;
n1= (struct node*)malloc(sizeof(struct node));
n2= (struct node*)malloc(sizeof(struct node));
n3= (struct node*)malloc(sizeof(struct node));
n1->data = 10;
n2->data = 20;
n3->data = 30;
n1->next = n2;
n2->next = n3;
n3->next = NULL;
printf("Node 1 data:%d\n", n1->data);
printf("Node 2 data:%d\n", n2->data);
printf("Node 3 data:%d\n", n3->data);
printf("Node 1 data:%d\n", n1->next->next->data);
free(n1);
free(n2);
free(n3);
return 0;
}
