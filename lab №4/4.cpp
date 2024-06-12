#include <iostream>
#include <vector>

using namespace std;

struct City{
    int code;
    int rating;
    int honorarium;


    City(int code_, int rating_, int honorarium_) {
        code = code_;
        rating = rating_;
        honorarium = honorarium_;
    };
};

//Дописать случай, когда равные рейтинги и гонорары
void siftUp_by_rating(vector<City> &arr, int i){
    while (arr[i].rating >= arr[(i - 1) / 2].rating){
        if (i <= 0){
            break;
        }
        if (arr[i].rating > arr[(i - 1) / 2].rating){
            swap(arr[i], arr[(i - 1) / 2]);
        }
        else if (arr[i].rating == arr[(i - 1) / 2].rating){
            if (arr[i].code > arr[(i - 1) / 2].code){
                swap(arr[i], arr[(i - 1) / 2]);
            }
        }
        i = (i - 1) / 2;
    }
}

void siftUp_by_honorarium(vector<City> &arr, int i){
    while (arr[i].honorarium >= arr[(i - 1) / 2].honorarium){
        if (i <= 0){
            break;
        }
        if (arr[i].honorarium > arr[(i - 1) / 2].honorarium){
            swap(arr[i], arr[(i - 1) / 2]);
        }
        else if (arr[i].honorarium == arr[(i - 1) / 2].honorarium){
            if (arr[i].code > arr[(i - 1) / 2].code){
                swap(arr[i], arr[(i - 1) / 2]);
            }
        }
        i = (i - 1) / 2;
    }
}

void siftDown_by_rating(vector<City> &arr, int i){
    while (2 * i + 1 < arr.size()){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < arr.size() && arr[right].rating >= arr[left].rating){
            if (arr[right].rating == arr[left].rating && arr[right].code > arr[left].code){
                j = right;
            }
            if (arr[right].rating > arr[left].rating){
                j = right;
            }
        }
        if (arr[i].rating > arr[j].rating){
            break;
        }
        else if (arr[i].rating == arr[j].rating){
            if (arr[i].code < arr[j].code){
                swap(arr[i], arr[j]);
            }
            else{
                break;
            }
        }
        else if(arr[i].rating < arr[j].rating){
            swap(arr[i], arr[j]);
        }
        i = j;
    }
}

void siftDown_by_honorarium(vector<City> &arr, int i){
    while (2 * i + 1 < arr.size()){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < arr.size() && arr[right].honorarium >= arr[left].honorarium){
            if (arr[right].honorarium == arr[left].honorarium && arr[right].code > arr[left].code)
                j = right;
            if (arr[right].honorarium > arr[left].honorarium)
                j = right;
        }
        if (arr[i].honorarium > arr[j].honorarium){
            break;
        }
        else if (arr[i].honorarium == arr[j].honorarium){
            if (arr[i].code < arr[j].code){
                swap(arr[i], arr[j]);
            }
            else{
                break;
            }
        }
        else if(arr[i].honorarium < arr[j].honorarium){
            swap(arr[i], arr[j]);
        }
        i = j;
    }
}

void insert_by_rating(int code, int rate, int honorar, vector<City> &one_heap){
    one_heap.emplace_back(code, rate, honorar);
    siftUp_by_rating(one_heap, one_heap.size() - 1);
}

void insert_by_honorarium(int code, int rate, int honorar, vector<City> &one_heap){
    one_heap.emplace_back(code, rate, honorar);
    siftUp_by_honorarium(one_heap, one_heap.size() - 1);
}

int extract_max_by_rating(vector<City> &one_heap) {
    if (!one_heap.empty()) {
        int min = one_heap[0].code;
        one_heap[0] = one_heap[one_heap.size() - 1];
        one_heap.pop_back();
        siftDown_by_rating(one_heap, 0);
        return min;
    } else{
        return -1;
    }
}

int extract_max_by_honorarium(vector<City> &one_heap) {
    if (!one_heap.empty()) {
        int min = one_heap[0].code;
        one_heap[0] = one_heap[one_heap.size() - 1];
        one_heap.pop_back();
        siftDown_by_honorarium(one_heap, 0);
        return min;
    } else{
        return -1;
    }
}

int extract_middle_by_honorarium(vector<City> &one_heap, int i) {
    if (!one_heap.empty()) {
        int min = one_heap[0].code;
        one_heap[i] = one_heap[one_heap.size() - 1];
        one_heap.pop_back();
        siftDown_by_honorarium(one_heap, i);
        return min;
    } else{
        return -1;
    }
}

int get_code(int elem, vector <City> &one_heap){
    for (int i = 0; i < one_heap.size(); i++){
        if (one_heap[i].code == elem){
            return i;
        }
    }
    return 0;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<City> Table_by_rating;
    vector<City> Table_by_honorarium;
    vector<string> Yes_No;
    vector<int> Connected_cities;
    vector<int> All_cities;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int code, rate, honorar;
        cin >> code >> rate >> honorar;
        insert_by_rating(code, rate, honorar, Table_by_rating);
        insert_by_honorarium(code, rate, honorar, Table_by_honorarium);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string per;
        cin >> per;
        Yes_No.push_back(per);
    }

//    for (int i = 0; i < n; i++) {
//        cout << Table_by_rating[i].code << " " << Table_by_rating[i].rating << " " << Table_by_rating[i].honorarium
//             << "\n";
//    }
//    cout << "--------\n";
//    for (int i = 0; i < n; i++) {
//        cout << Table_by_honorarium[i].code << " " << Table_by_honorarium[i].rating << " "
//             << Table_by_honorarium[i].honorarium << "\n";
//    }
//    cout << "--------\n";

    if (!Yes_No.empty()) {
        while (!Table_by_rating.empty()) {
            //cout << Table_by_rating[0].code << " " << Table_by_honorarium[0].code << "\n";
            if (Table_by_rating[0].code == Table_by_honorarium[0].code) {
                extract_max_by_rating(Table_by_rating);
                int extracted_honorar = extract_max_by_honorarium(Table_by_honorarium);
                All_cities.push_back(extracted_honorar);
            } else {
                if (Yes_No[0] == "YES" && !Yes_No.empty()) {
                    Connected_cities.push_back(Table_by_rating[0].code);
                    All_cities.push_back(Table_by_rating[0].code);
                    int agree_index = get_code(Table_by_rating[0].code, Table_by_honorarium);
                    extract_max_by_rating(Table_by_rating);
                    extract_middle_by_honorarium(Table_by_honorarium, agree_index);
                    Yes_No.erase(Yes_No.begin());
                } else if (Yes_No[0] == "NO" && !Yes_No.empty()) {
                    Connected_cities.push_back(Table_by_rating[0].code);
                    int agree_index = get_code(Table_by_rating[0].code, Table_by_honorarium);
                    extract_max_by_rating(Table_by_rating);
                    extract_middle_by_honorarium(Table_by_honorarium, agree_index);
                    Yes_No.erase(Yes_No.begin());
                } else if (Yes_No.empty()) {
                    extract_max_by_rating(Table_by_rating);
                }
            }
        }
    }
    else{
        while (!Table_by_rating.empty()) {
            //cout << Table_by_rating[0].code << " " << Table_by_honorarium[0].code << "\n";
            if (Table_by_rating[0].code == Table_by_honorarium[0].code) {
                extract_max_by_rating(Table_by_rating);
                int extracted_honorar = extract_max_by_honorarium(Table_by_honorarium);
                All_cities.push_back(extracted_honorar);
            }
            else{
                extract_max_by_rating(Table_by_rating);
            }
        }
    }

    for (int i = 0; i < Connected_cities.size(); i++) {
        cout << Connected_cities[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < All_cities.size(); i++) {
        cout << All_cities[i] << " ";
    }

    return 0;

}
