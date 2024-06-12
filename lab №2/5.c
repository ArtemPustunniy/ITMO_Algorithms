#include <stdio.h>

long long count = 0;

void Merge(int *arr, int *left_arr, int len_left, int *right_arr, int len_right) {
    int i = 0 ;
    int j = 0;
    int k = 0;

    while (i < len_left && j < len_right)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
            k++;
            count += len_left - (i);
        }

    }

    while (i < len_left)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < len_right)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr, int size) {
    if (size <= 1) {
        return;
    }

    int middle = size / 2;
    int left_arr[middle];
    int right_arr[size - middle];

    for (int i = 0; i < middle; i++) {
        left_arr[i] = arr[i];
    }

    for (int i = middle; i < size; i++) {
        right_arr[i - middle] = arr[i];
    }

    MergeSort(left_arr, middle);
    MergeSort(right_arr, size - middle);
    Merge(arr, left_arr, middle, right_arr, size - middle);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, n);

    printf("%lld", count);

    return 0;
}
