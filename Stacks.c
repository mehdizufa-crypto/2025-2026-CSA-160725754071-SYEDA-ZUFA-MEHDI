#include<stdio.h>
#define MAX 5
//stack ADT
struct stack
{
int data [MAX];
int top;
};
struct stack s;//global stack object
//initialize stack
void init()
{
s.top=-1;
}
//push operation
void push(int x)
{
if(s.top==MAX-1)
printf("Stack Overflow");
else
s.data[++s.top]=x;
}
//pop operation
void pop()
{
if(s.top==-1)
printf("Stack Underflow");
else
printf("Popped:%d\n", s.data[s.top--]);
}
//display operation
void display()
{
if(s.top==-1)
printf("Stack is empty");
else
{
for(int i=s.top; i>=0; i--)
printf("%d ", s.data[i]);
printf("\n");
}
}
int main()
{
init();
push(10);
push(20);
push(30);
display();
pop();
display();
return 0;
}
