#include "blazingio.hpp"
#include "string"
#include "vector"
using namespace std;

int main(){

    string first, second;
    cin >> first;
    cin >> second;

    int n = first.length();
    int m = second.length();
    vector <int> result;

    for (int i = 0; i <= n - m; i++){
        int j = 0;
        while (j < m){
            if (first[i + j] != second[j])
                break;
            j++;
        }
        if (j == m){
            result.push_back(i);
        }
    }

    cout << result.size() << "\n";
    for (auto i: result){
        cout << i << " ";
    }

    return 0;

}
