#include <iostream>
#include <string>

using namespace std;

void countingSort(string *arr, int n, int index) {
    const int countRange = 26;
    int *count = new int[countRange];
    for (int i = 0; i < countRange; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i][index] - 'a']++;
    }

    for (int i = 1; i < countRange; i++) {
        count[i] += count[i - 1];
    }

    string* sorted = new string[n];
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[arr[i][index] - 'a'] - 1] = arr[i];
        count[arr[i][index] - 'a']--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }

    delete[] count;
    delete[] sorted;
}

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    string *arr = new string[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string stroka;
        cin >> stroka;
        arr[i] = stroka;
    }

    for (int i = k - 1; i >= k - t; i--) {
        countingSort(arr, n, i);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}
