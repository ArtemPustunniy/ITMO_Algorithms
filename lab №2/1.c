#include <stdio.h>
#include <stdlib.h>

void insert_sort(int *arr, int len)
{
    for (int j = 1; j < len; j++)
    {
        int k = j;
        while (k > 0 && arr[k - 1] > arr[k])
        {
            int temp = arr[k - 1];
            arr[k - 1] = arr[k];
            arr[k] = temp;
            k--;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *mas = malloc(sizeof(int) * n);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &mas[i]);
    }
    insert_sort(mas, n);

    for (int  i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }

    return 0;
}
