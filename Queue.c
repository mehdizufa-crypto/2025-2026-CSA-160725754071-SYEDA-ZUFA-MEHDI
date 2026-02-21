#include<stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE], front=-1, rear=-1;
void insert(int value)
{
if(rear==MAX_SIZE-1)
printf("\n\t Queue is overflow \n");
else{
if(front==-1)
front=0;
queue[++rear]=value;
printf("\n\t %d has been inserted into the queue \n", value);
}
}
void delete()
{
if(front==-1 || front>rear)
printf("\n\t Queue is underflow \n");
else
{
printf("\n\t %d has been deleted from the queue \n", queue [front++]);
if(front>rear)
front=rear=-1;
}
}
void display ()
{
if(front==-1 || front>rear)
printf("\n\t queue is empty \n");
else{
printf("\n\t The elements in the queue are: \n");
for(int i=front; i<=rear; i++)
printf("\t %d\n", queue[i]);
}
}
int main()
{
int choice, x;
printf("\n\t Queue operations using arrays");
printf("\n\t----------\n");
do{
printf("\n\t1. Insert \n\t2.Delete \n\t3.Display \n\t4.Exit \n");
printf("\n\t Enter the choice");
scanf("%d", &choice);
switch (choice){
case 1:
printf("\n\t Enter the value to be inserted:");
scanf("%d", &x);
insert(x);
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
printf("\n\t Exit Point \n");
break;
default:
printf("\n\t Please enter a valid choice (1/2/3/4)\n");
}
}
while(choice!=4);
return 0;
}
