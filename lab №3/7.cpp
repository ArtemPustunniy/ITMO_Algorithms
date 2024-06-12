#include <iostream>


int partition(int *arr, int k, int one_diapazon, int len){
    int etalon = arr[0];
    int count = 1;
    for (int i = 0; i < len; i++){
        if (etalon + one_diapazon <= arr[i]){
            count++;
            etalon = arr[i];
        }
    }
    if (count >= k)
        return 1;
    else
        return 0;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int mas[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }
    int left, right;
    left = 0;
    right = 1000000009;
    while (right - left > 1){
        int pivot = (left + right) / 2;
        if (partition(mas, k, pivot, n) == 1){
            left = pivot;
        }
        else{
            right = pivot;
        }
    }
    std::cout << left;

    return 0;
}
