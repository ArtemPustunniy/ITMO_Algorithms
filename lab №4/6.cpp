#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
struct Node{
    long long number;
    long long number_in_pow;
    long long pow;


    Node(long long number_, long long number_in_pow_, long long pow_) {
        number = number_;
        number_in_pow = number_in_pow_;
        pow = pow_;
    };
};

void siftUp(vector<Node> &arr, int i){
    while (arr[i].number_in_pow < arr[(i - 1) / 2].number_in_pow){
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftDown(vector<Node> &arr, int i){
    while (2 * i + 1 < arr.size()){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < arr.size() && arr[right].number_in_pow < arr[left].number_in_pow){
            j = right;
        }
        if (arr[i].number_in_pow <= arr[j].number_in_pow){
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}
// Добавление в самом начале в кучу
void insert_into_heap_initialize(int num, vector<Node> &one_heap){
    one_heap.emplace_back(num, num, 1);
    siftUp(one_heap, one_heap.size() - 1);
}
// Замена степени в Ноде и просеивание кучи
void decrease(vector<Node> &one_heap) {
    one_heap[0].number_in_pow = one_heap[0].number_in_pow * one_heap[0].number_in_pow;
    one_heap[0].pow *= 2;
    siftDown(one_heap, 0);
}

// Решето Эратосфена
vector<long long> sieveOfEratosthenes(int n) {
    vector<long long> result(n + 1, 0);
    result[n] = n;

    for (long long i = 2; i <= sqrt(n); i++) {
        if (result[i] == 0) {
            long long shuttle = i * i;
            while (shuttle <= n) {
                result[shuttle] = i;
                shuttle += i;
            }
        }
    }

    return result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<Node> heap;
    vector<long long> simple_divisors;
    vector<long long> result_of_sieve;
    result_of_sieve = sieveOfEratosthenes(6000000);
    for (int p = 2; p < result_of_sieve.size(); p++) {
        if (result_of_sieve[p] == 0) {
            simple_divisors.push_back(p);
        }
    }
    for (int i = 0; i < n; i++){
        insert_into_heap_initialize(simple_divisors[i], heap);
        //cout << simple_divisors[i] << "\n";
    }

    vector<long long> divisors;
    int count = 0;
    while (count != n){
        //cout << heap[0].number << " " << heap[0].pow * 2 << "\n";
        decrease(heap);
        count++;
    }
    //cout << "\n";

    for (int i = 0; i < heap.size(); i++){
        //cout << heap[i].number << " " << heap[i].pow << "\n";
        if (heap[i].pow > 1){
            for (int j = 0; j < heap[i].pow - 1; j++){
                divisors.push_back(heap[i].number);
            }
        }
    }
    cout << divisors.size() << "\n";
    sort(divisors.begin(), divisors.end());

    for (int i = 0; i < divisors.size(); i++){
        cout << divisors[i] << " ";
    }


//    long long d_x = 1;
//    long long x = 1;
//    long long gran = pow(2, n);
//    while (d_x != gran){
//        d_x *= 2;
//        x *= heap[0].number_in_pow;
//        decrease(heap);
//    }
//    cout << d_x << " " << x << "\n";
//
//    vector<long long> divisors;
//
//    divisors = primeFactors(x);


//    for (int i = 0; i < divisors.size(); i++){
//        cout << divisors[i] << " ";
//    }

    return 0;
}
