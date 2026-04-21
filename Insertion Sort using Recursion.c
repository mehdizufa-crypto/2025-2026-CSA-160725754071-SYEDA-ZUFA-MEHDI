#include<stdio.h>
void insertionSort(int a[], int n)
{
    if(n <= 1)
        return;


    insertionSort(a, n - 1);


    int key = a[n - 1];
    int j = n - 2;

    while(j >= 0 && a[j] > key)
    {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = key;
}

int main()
{
    int a[10], n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
