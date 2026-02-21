#include<stdio.h>
struct student
{
int ID;
char name [20];
float marks;
};
int main()
{
struct student s[5];
for(int i=0;i<5;i++)
{
printf("Enter student details for student=%d\n", i+1);
printf("ID:");
scanf("%d", &s[i].ID);
printf("Name:");
scanf("%s", &s[i].name);
printf("Marks:");
scanf("%f", &s[i].marks);
}
printf("\n---Student Details---\n");
for(int i=0; i<5; i++)
{
printf("ID=%d\n", s[i].ID);
printf("Name=%s\n", s[i].name);
printf("Marks=%2f\n", s[i].marks);
}
}
