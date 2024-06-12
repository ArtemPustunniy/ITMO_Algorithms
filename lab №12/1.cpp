#include "iostream"
#include "vector"

using namespace std;

vector<pair<long long, int>> xss;
vector<pair<long long, int>> yss;

vector<pair<long long, long long>> matching;

int Full = 600000;


int my_hash(long long key, int i) {
    return (key + i * i) % Full;
}

void open_order(vector<pair<long long, int>> &this_table, long long this_cord, int &key, bool &added){
    int i = 0;
    while (true){
        key = my_hash(this_cord, i);
        if (this_table[key].first == -1)
        {
            break;
        }
        if (this_table[key].first == this_cord) {
            this_table[key].second++;
            added = true;
            break;
        }
        i++;
    }
}

void insert(long long x, long long y){
    bool added = false;
    int key;
    open_order(xss, x, key, added);
    if (!added){
        xss[key] = {x, 1};
    }
    added = false;
    open_order(yss, y, key, added);
    if (!added){
        yss[key] = {y, 1};
    }
}

int search(vector<pair<long long, int>> &table, int coord){
    int i = 0;
    int key;
    while (true){
        key = my_hash(coord, i);
        if (table[key].first == -1){
            break;
        }
        else if (table[key].first == coord){
            return table[key].second;
        }
        i++;
    }
    return 0;
}

void first_check(vector<pair<long long, int>> &this_table, int &this_max, int &cord, int type_of_check){
    if (type_of_check == 1){
        for (int i = 0; i < matching.size(); i++){
            int res = search(this_table, matching[i].first);
            if (this_max < res){
                this_max = res;
                cord = matching[i].first;
            }
        }
    }
    else{
        for (int i = 0; i < matching.size(); i++){
            int res = search(this_table, matching[i].second);
            if (this_max < res){
                this_max = res;
                cord = matching[i].second;
            }
        }
    }

}

void second_check(vector<pair<long long, int>> &this_table, int cord, int type_of_check){
    int i = 0;
    while (true){
        int key = my_hash(cord, i);
        if (this_table[key].first == cord){
            this_table[key].second = -2;
            this_table[key].first = -2;
            break;
        }
        i++;
    }
    auto this_i = matching.begin();
    if (type_of_check == 1){
        while (this_i != matching.end()){
            if (this_i->first == cord){
                matching.erase(this_i);
                continue;
            }
            this_i++;
        }
    }
    else{
        while (this_i != matching.end()){
            if (this_i->second == cord){
                matching.erase(this_i);
                continue;
            }
            this_i++;
        }
    }

}

int main(){
    int n;
    int x_vvod, y_vvod;
    cin >> n;
    xss.resize(Full, {-1, -1});
    yss.resize(Full, {-1, -1});
    for (int i = 0; i < n; i++){
        cin >> x_vvod >> y_vvod;
        insert(x_vvod, y_vvod);
        matching.emplace_back(x_vvod, y_vvod);
    }
    for (int _ = 0; _ < 3; _++){
        if (matching.empty())
            continue;
        int x_close = 0;
        int x;
        first_check(xss, x_close, x, 1);
        int y_close = 0;
        int y;
        first_check(yss, y_close, y, 2);
        if (x_close < y_close){
            second_check(yss, y, 2);
        }
        else{
            second_check(xss, x, 1);
        }
    }
    if (matching.empty()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
