#include<stdio.h>

void bubblesort(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)      {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[10], i, n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bubblesort(a, n);

    printf("Sorted Elements:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
