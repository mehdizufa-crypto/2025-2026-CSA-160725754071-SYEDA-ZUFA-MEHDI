#include<stdio.h>
void selectionSort(int a[], int n, int i)
{
    if(i >= n - 1)
        return;

    int j, min = i, temp;

      for(j = i + 1; j < n; j++)
    {
        if(a[j] < a[min])
            min = j;
    }

    // Swap
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
    selectionSort(a, n, i + 1);

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

    selectionSort(a, n, 0);

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
