#include <stdio.h>
#include <stdlib.h>
// arr - массив
// left - левая граница
// right - правая граница
void quick_sort(int *arr, int left, int right, int start)
{
    if(left > right)
        return;
    int middle = start;
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j, arr[(left + j - 1) / 2]);
    quick_sort(arr, i, right, arr[(i + right + 1) / 2]);


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

    quick_sort(mas, 0, n - 1, 0);
    for (int  i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }


    return 0;
}
