#include<stdio.h>
int main()
{
int a[5];
int *p0, *p1, *p2, *p3, *p4;
a[0]=10;
a[1]=20;
a[2]=0;
a[3]=40;
a[4]=50;
p0=&a[0];
p1=&a[1];
p2=&a[2];
p3=&a[3];
p4=&a[4];
printf("the value of a[0]= %d\n", a[0]);
printf("the value of a[1]= %d\n", a[1]);
printf("the value of a[2]= %d\n", a[2]);
printf("the value of a[3]= %d\n", a[3]);
printf("the value of a[4]= %d\n", a[4]);
//values of addresses
printf("The address of a[0]=%p\n", p0);
printf("The address of a[1]=%p\n", p1);
printf("The address of a[2]=%p\n", p2);
printf("The address of a[3]=%p\n", p3);
printf("The address of a[4]=%p\n", p4);
}
