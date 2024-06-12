#include <iostream>
#include <vector>
#include <string>

using namespace std;

void siftUp(vector<int> &arr, int i){
    while (arr[i] < arr[(i - 1) / 2]){
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftDown(vector<int> &arr, int i){
    while (2 * i + 1 < arr.size()){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < arr.size() && arr[right] < arr[left]){
            j = right;
        }
        if (arr[i] <= arr[j]){
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

void create(vector<vector<int>*> &all_heaps_in_create){
    auto *new_heap = new vector<int>();
    all_heaps_in_create.push_back(new_heap);
}

void insert(int x, vector<int> &one_heap){
    one_heap.push_back(x);
    siftUp(one_heap, one_heap.size() - 1);
}

int extract_min(vector<int> &one_heap) {
    if (one_heap.size() > 0) {
        int min = one_heap[0];
        one_heap[0] = one_heap[one_heap.size() - 1];
        one_heap.pop_back();
        siftDown(one_heap, 0);
        return min;
    } else{
        return -1;
    }
}

void merge(vector<int> &first_heap, vector<int> &second_heap, vector<vector<int>*> &all_heaps_in_merge){
    create(all_heaps_in_merge);
    for (int i = 0; i < first_heap.size(); i++){
        all_heaps_in_merge[all_heaps_in_merge.size() - 1]->push_back(first_heap[i]);
    }
    for (int i = 0; i < second_heap.size(); i++){
        all_heaps_in_merge[all_heaps_in_merge.size() - 1]->push_back(second_heap[i]);
        siftUp(*all_heaps_in_merge[all_heaps_in_merge.size() - 1], all_heaps_in_merge[all_heaps_in_merge.size() - 1]->size() - 1);
    }
}

void decrease_key(vector<int> &all_heaps_in_decrease_key, int k, int x, int y){
    if (x == y){
        return;
    }

    for (int i = 0; i < all_heaps_in_decrease_key.size(); i++){
        if (all_heaps_in_decrease_key[i] == x) {
            all_heaps_in_decrease_key[i] = y;
            siftUp(all_heaps_in_decrease_key, i);
            break;
        }
    }

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>*> all_heaps;
    while (cin){
        string command;
        cin >> command;
        if (command == "create"){
            create(all_heaps);
        }
        else if (command == "insert"){
            int k;
            int x;
            cin >> k >> x;
            insert(x, *all_heaps[k]);
        }
        else if (command == "extract-min"){
            int k;
            cin >> k;
            int answer = extract_min(*all_heaps[k]);
            if (answer == -1){
                cout << '*' << '\n';
            }
            else{
                cout << answer << "\n";
            }
        }
        else if (command == "merge"){
            int k;
            int m;
            cin >> k >> m;
            merge(*all_heaps[k], *all_heaps[m], all_heaps);
        }
        else if (command == "decrease-key"){
            int k;
            int x;
            int y;
            cin >> k >> x >> y;
            decrease_key(*all_heaps[k], k, x, y);
        }
    }
    return 0;
}
