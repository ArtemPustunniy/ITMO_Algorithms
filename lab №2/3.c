#include <stdio.h>
#include <stdlib.h>

void quick_sort(long long *arr, long long left, long long right) {
    if (left >= right)
        return;
    long long middle = arr[(left + right) / 2];
    long long i = left;
    long long j = right;
    while (i <= j) {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i <= j) {
            long long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main() {
    long long n;
    scanf("%lld", &n);
    long long *mas = malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &mas[i]);
    }

    quick_sort(mas, 0, n - 1);
    /*for (int i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }*/
    //printf("\n");
    long long summa = 0;
    long long i = n - 1;
    long long first_storona = 0;
    long long second_storona = 0;
    long long third_storona = 0;
    long long fourth_storona = 0;
    while (i >= 0) {
        if ((first_storona == second_storona) && (third_storona == fourth_storona) && (first_storona != 0) && (third_storona != 0)) {
            summa += (second_storona * third_storona);
            first_storona = 0;
            second_storona = 0;
            third_storona = 0;
            fourth_storona = 0;
            i--;
            continue;
        }
        if ((first_storona == 0) && (third_storona == 0) && (i > 0)) {
            if (mas[i] == mas[i - 1]) {
                first_storona = mas[i];
                second_storona = mas[i - 1];
                i--;
                continue;
            }
            if (mas[i] - mas[i - 1] == 1) {
                first_storona = mas[i - 1];
                second_storona = mas[i - 1];
                i--;
                continue;
            }
        }
        if ((first_storona != 0) && (third_storona == 0) && (fourth_storona == 0) && (i > 0)) {
            third_storona = mas[i - 1];
            i--;
            continue;
        }
        if ((first_storona != 0) && (third_storona != 0) && (fourth_storona == 0) && (i > 0)) {
            if ((third_storona == mas[i - 1])) {
                fourth_storona = third_storona;
                i--;
                continue;
            }
            if ((third_storona - mas[i - 1] == 1) && (second_storona != third_storona)) {
                fourth_storona = mas[i - 1];
                third_storona = third_storona - 1;
                i--;
                continue;
            }
            if ((third_storona - mas[i - 1] == 1) && (third_storona == second_storona)) {
                fourth_storona = mas[i - 1];
                third_storona = mas[i - 1];
                i--;
                continue;
            }
            if ((third_storona - mas[i - 1] > 1) && (third_storona == second_storona)) {
                    third_storona = 0;
                    second_storona = mas[i];
                    first_storona = mas[i];
                    //i--;
                    continue;
            }
            if ((third_storona - mas[i - 1] > 1) && (second_storona != third_storona)) {
                third_storona = 0;
                continue;
            }
        }
        i--;
    }
    printf("%lld", summa);

    return 0;
}
