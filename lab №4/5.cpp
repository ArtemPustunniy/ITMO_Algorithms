#include <iostream>

using namespace std;

void siftUp(int *arr, int n, int i)
{
    int father = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[father])
        father = left;

    if (right < n && arr[right] > arr[father])
        father = right;

    if (father != i)
    {
        swap(arr[i], arr[father]);

        siftUp(arr, n, father);
    }
}

int main()
{
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++){
        cin >> mas[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--)
        siftUp(mas, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = mas[0];
        mas[0] = mas[i];
        mas[i] = temp;

        siftUp(mas, i, 0);
    }

    for (int i = 0; i < n; i++){
        cout << mas[i] << " ";
    }
}

