#include<stdio.h>
void bubblesort(int a[], int n)
{
if(n==1)
return;
int i, temp;
for(i=0; i<n-1; i++)
{
if(a[i]>a[i+1])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}}
//recursive call for remaining array
bubblesort(a,n-1);
}
int main(){
int a[10], i, n;
printf("Enter the value of n:");
scanf("%d", &n);
printf("Enter the elements:\n");
for(i=0; i<n; i++)
{
scanf("%d", &a[i]);
}
bubblesort(a, n);
printf("Sorted Elements:\n");
for(i=0; i<n;i++)
{
printf("%d\n", a[i]);}
return 0;
}
