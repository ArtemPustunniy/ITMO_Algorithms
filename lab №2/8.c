#include <iostream>

using namespace std;

struct sorted {
    int elem;
    int elem_after_sort;
};

void mergeSort(struct sorted *m, int left, int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;

    mergeSort(m, left, mid);
    mergeSort(m, mid + 1, right);
    int leftIndex = left;
    int rightIndex = mid + 1;
    struct sorted *tmp = new struct sorted[right + 1];
    for (int step = 0; step < right - left + 1; step++)
    {
        if ((rightIndex > right) ||
            ((leftIndex <= mid) && (m[leftIndex].elem <= m[rightIndex].elem))) {
            tmp[step] = m[leftIndex];
            tmp[step].elem_after_sort -= rightIndex - mid - 1;
            leftIndex++;
        } else {
            tmp[step] = m[rightIndex];
            tmp[step].elem_after_sort += mid - leftIndex + 1;
            rightIndex++;
        }
    }

    for (int step = 0; step < right - left + 1; step++)
        m[left + step] = tmp[step];

    delete[] tmp;
}

int main() {
    int n;
    cin >> n;

    struct sorted m[n];

    for (int i = 0; i < n; i++) {
        cin >> m[i].elem;
        m[i].elem_after_sort = m[i].elem;
    }

    mergeSort(m, 0, n - 1);

    short correct = 1;

    for (int i = 0; i < n - 1; i++) {
        if (m[i].elem_after_sort > m[i+1].elem_after_sort) {
            cout << ":(";
            correct = 0;
            break;
        }
    }

    if (correct) {
        for (auto i: m) {
            cout << i.elem_after_sort << " ";
        }
    }
}
