#include <iostream>
#include <vector>

using namespace std;

struct Person{
    long long cellary;
    long long time_of_end;

    Person(long long cel, long long time_) {
        cellary = cel;
        time_of_end = time_;
    };
};


void siftUp_cellary(vector<Person> &arr, long long i){
    while (arr[i].cellary < arr[(i - 1) / 2].cellary){
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftUp_time(vector<Person> &arr, long long i){
    while (arr[i].time_of_end < arr[(i - 1) / 2].time_of_end){
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftDown_cellary(vector<Person> &arr, long long i){
    while (2 * i + 1 < arr.size()){
        long long left = 2 * i + 1;
        long long right = 2 * i + 2;
        long long j = left;
        if (right < arr.size() && arr[right].cellary < arr[left].cellary){
            j = right;
        }
        if (arr[i].cellary <= arr[j].cellary){
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

void siftDown_time(vector<Person> &arr, long long i){
    while (2 * i + 1 < arr.size()){
        long long left = 2 * i + 1;
        long long right = 2 * i + 2;
        long long j = left;
        if (right < arr.size() && arr[right].time_of_end < arr[left].time_of_end){
            j = right;
        }
        if (arr[i].time_of_end <= arr[j].time_of_end){
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

void insert_free_(long long cel, vector<Person> &one_heap){
    one_heap.emplace_back(cel, 0);
    siftUp_cellary(one_heap, one_heap.size() - 1);
}

void insert_busy(long long cel, long long time_end, vector<Person> &one_heap){
    one_heap.emplace_back(cel, time_end);
    siftUp_time(one_heap, one_heap.size() - 1);
}

long long extract_min_free_(vector<Person> &one_heap) {
    if (!one_heap.empty()) {
        long long min = one_heap[0].cellary;
        one_heap[0] = one_heap[one_heap.size() - 1];
        one_heap.pop_back();
        siftDown_cellary(one_heap, 0);
        return min;
    } else{
        return -1;
    }
}

long long extract_min_busy(vector<Person> &one_heap) {
    if (!one_heap.empty()) {
        long long min = one_heap[0].cellary;
        one_heap[0] = one_heap[one_heap.size() - 1];
        one_heap.pop_back();
        siftDown_time(one_heap, 0);
        return min;
    } else{
        return -1;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    vector <Person> busy;
    vector <Person> free_;
    for (long long i = 0; i < n; i++){
        long long vvod;
        cin >> vvod;
        insert_free_(vvod, free_);
    }
    long long count_cellary = 0;
    for (long long i = 0; i < m; i++){
        long long start, continious;
        cin >> start >> continious;
        if (busy.empty()){
            long long shavermer = extract_min_free_(free_);
            insert_busy(shavermer, start + continious, busy);
            count_cellary += shavermer * continious;
        }
        else{
            while (busy[0].time_of_end <= start && !busy.empty()){
                long long shavermer = extract_min_busy(busy);
                insert_free_(shavermer, free_);
            }
            long long new_shavermer = extract_min_free_(free_);
            if (new_shavermer != -1){
                insert_busy(new_shavermer, start + continious, busy);
                count_cellary += new_shavermer * continious;
            }
        }
    }

    cout << count_cellary;


    return 0;
}
