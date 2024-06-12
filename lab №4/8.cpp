#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int base = 1000000000;


int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string cin_first;
    cin >> cin_first;
    vector<int> first;
    for (int i = cin_first.size(); i > 0; i -= 9){
        if (i < 9){
            first.push_back(stoi(cin_first.substr(0, i)));
        }
        else{
            first.push_back(stoi(cin_first.substr(i - 9, 9)));
        }
    }
    vector<int> second;
    for (int j = 0; j < n - 1; j++){
        string cin_second;
        cin >> cin_second;
        for (int i = cin_second.size(); i > 0; i -= 9){
            if (i < 9){
                second.push_back(stoi(cin_second.substr(0, i)));
            }
            else{
                second.push_back(stoi(cin_second.substr(i - 9, 9)));
            }
        }
        int ostatok = 0;
        int i = 0;
        while (i < max(first.size(), second.size()) || ostatok){
            if (i == first.size()){
                first.push_back(0);
            }
            if (i < second.size()){
                first[i] += ostatok + second[i];
            }
            else{
                first[i] += ostatok;
            }
            ostatok = (first[i] >= base);
            if (ostatok){
                first[i] -= base;
            }
            i++;
        }
        second.clear();
    }

    if (first.empty()){
        cout << 0;
    }
    else{
        cout << first.back();
    }
    for (int k = (int)first.size() - 2; k >= 0; k--){
        cout << setfill('0') << setw(9) << first[k];
        //printf("%09d", first[k]);
    }
//    if (first.empty()){
//        cout << 0;
//    }
//    else{
//        cout << first.back();
//    }
//    for (int k = (int)first.size() - 2; k >= 0; k--){
//        cout << ()first[k];
//    }
    return 0;
}
