#include <iostream>
#include <string>

using namespace std;


void countingSort(long long *mas, string *arr, long long size) {
    long long maxVal = 0;

    for (long long i = 0; i < size; i++) {
        if (mas[i] > maxVal) {
            maxVal = mas[i];
        }
    }

    long long *count = new long long[maxVal + 1];
    long long *new_mas = new long long[size];
    string *new_arr = new string[size];

    for (long long i = 0; i < maxVal + 1; i++) {
        count[i] = 0;
    }

    for (long long i = 0; i < size; i++) {
        count[mas[i]] = count[mas[i]] + 1;
    }

    for (long long i = 1; i < maxVal + 1; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (long long i = size - 1; i >= 0; i--) {
        new_mas[count[mas[i]] - 1] = mas[i];
        new_arr[count[mas[i]] - 1] = arr[i];
        count[mas[i]]--;
    }

    for (long long i = 0; i < size; i++) {
        mas[i] = new_mas[i];
        arr[i] = new_arr[i];
    }

}

long long rightBinarySearch(long long *arr, long long size, long long target) {
//    if (target < arr[0]){
//        return -2;
//    }
    long long left = 0;
    long long right = size - 1;
    long long res = -1;
    while (left <= right) {
        long long middle = left + (right - left) / 2;
        if (arr[middle] <= target) {
            res = middle;
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return res;
}

long long leftBinarySearch(long long *arr, long long size, long long target) {
//    if (target > arr[size - 1]){
//        return -2;
//    }
    long long left = 0;
    long long right = size - 1;
    long long res = -1;
    while (left <= right){
        long long middle = left + (right - left) / 2;
        if (arr[middle] >= target){
            res = middle;
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    std::cin >> n;
    cin.ignore();
    long long mas[n];
    for (long long i = 0; i < n; i++) {
        cin >> mas[i];
    }
    cin.ignore();

    string *arr = new string[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countingSort(mas, arr, n);
    long long pref_summs[n + 2];
    long long xors_arr[n + 2];
    pref_summs[0] = 0;
    xors_arr[0] = 0;
    for (long long i = 1; i < n + 2; i++){
        pref_summs[i] = pref_summs[i - 1] + mas[i - 1];
        xors_arr[i] = xors_arr[i - 1] ^ mas[i - 1];
    }

    for (long long i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << mas[i];
            break;
        }
        cout << mas[i] << " ";
    }
    cout << "\n";
    for (long long i = 0; i < n; i++) {
        if (i == n - 1) {
            std::cout << arr[i];
            break;
        }
        cout << arr[i] << " ";
    }
    cout << "\n";
    long long q;
    cin >> q;
    cin.ignore();
    for (long long i = 0; i < q; i++) {
        string command;
        long long left;
        long long right;
        cin >> command >> left >> right;
        long long left_search = leftBinarySearch(mas, n, left);;
        long long right_search = rightBinarySearch(mas, n, right);;

        if (left_search == -1 || right_search == -1){
            cout << 0 << "\n";
        }
        else {
            if (command == "Count") {
                long long answer;
                answer = right_search - left_search + 1;
                cout << answer << "\n";
            }
            else if (command == "Sum") {
                long long answer;
                answer = pref_summs[right_search + 1] - pref_summs[left_search];
                cout << answer << "\n";
            }
            else if (command == "Xor") {
                long long answer;
                answer = xors_arr[right_search + 1] ^ xors_arr[left_search];
                cout << answer << "\n";
            }
        }
        //delete[]comands;
    }
    return 0;
}
