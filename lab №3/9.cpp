#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(long long *arr, long long left, long long right, long long start)
{
    if(left > right)
        return;
    long long middle = start;
    long long i = left;
    long long j = right;
    while (i <= j)
    {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quick_sort(arr, left, j, arr[(left + j - 1) / 2]);
    quick_sort(arr, i, right, arr[(i + right + 1) / 2]);
}


int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    const long long rows = 2;
    long long n, k;
    cin>> n >> k;
    cin.ignore();

    long long *women = new long long[n];
    long long *men = new long long[n];

    for (long long i = 0; i < n; i++){
        cin >> women[i];
    }

    for (long long i = 0; i < n; i++){
        cin >> men[i];
    }

    quick_sort(women, 0, n - 1, women[n / 2]);
    quick_sort(men, 0, n - 1, men[n / 2]);

//    for (long long i = 0; i < n; i++){
//        cout << men[i] << " ";
//    }
//    cout << "\n";
//    for (long long i = 0; i < n; i++){
//        cout << women[i] << " ";
//    }
//    cout << "\n";


    long long **mas = new long long*[rows];

    for (long long i = 0; i < rows; i++){
        mas[i] = new long long[n];
    }

    for (long long i = 0; i < n; i++){
        mas[0][i] = women[i];
        mas[1][i] = men[i];
    }

//    if (k == n * n){
//        cout << mas[0][n - 1] + mas[1][n - 1];
//        return 0;
//    }

//    if (n == 1) {
//        cout << mas[0][0];
//        return 0;
//    }
//
//    if (k == 1){
//        cout << mas[0][0] + mas[1][0];
//        return 0;
//    }
/// 1 2 2 3 5
///
    long long left = mas[0][0] + mas[1][0] - 1;
    long long right = mas[0][n - 1] + mas[1][n - 1] + 1;

    long long target = k - 1;
    while(left < right - 1){
        long long middle = left + (right - left) / 2;
        long long counter = 0;
        long long max_man = n - 1; /// Беру наибольшего мужика
        long long min_woman = 0; /// Беру наименьшую женщину

        while (max_man >= 0 && min_woman < n){
            //cout << men[max_man] + women[min_woman] << " " << middle << "\n";
            /// Если сумма мужика и женщины меньше, чем middle
            if (men[max_man] + women[min_woman] < middle){
                counter += max_man + 1;
                min_woman++;
            }
            /// Если сумма мужика и женщины больше или равно middle
            else if(men[max_man] + women[min_woman] >= middle){
                max_man--;
            }
        }
//        cout << "count" << counter << "\n";
//        cout << "\n";

        if(counter <= target){
            left = middle;
        }
        else{
            right = middle;
        }
    }
    cout << left;

    return 0;
}
