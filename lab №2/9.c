#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, int left, int right, int k, int pos)
{
    if(left > right)
        return;
    int middle = arr[(left + right) / 2];
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
        if (left <= (pos - k) && j >= (pos - k)){
            quick_sort(arr, left, j, k, pos);
        }
        else {
            quick_sort(arr, i, right, k, pos);
        }



}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int A, B, C, a1, a2;
    scanf("%d %d %d %d %d", &A, &B, &C, &a1, &a2);
    int *mas = malloc(sizeof(int) * n);
    mas[0] = a1;
    mas[1] = a2;
    for (int i = 2; i < n; i++)
    {
        mas[i] = mas[i - 2] * A + mas[i - 1] * B + C;
    }
//    for(int i = 0; i < n; i++)
//    {
//        printf("%d ", mas[i]);
//    }
//    printf("\n");
    quick_sort(mas, 0, n - 1, k, n);
//    for(int i = 0; i < n; i++)
//    {
//        printf("%d ", mas[i]);
//    }
//    printf("\n");
    int res = mas[n - k];
//    printf("%d ", res);
    for (int i = n - k + 1; i < n; i++)
    {
//        printf("%d ", mas[i]);
        res^= mas[i];
    }
    printf("%d", res);
    return 0;
}

