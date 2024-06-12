#include "blazingio.hpp"
#include "string"
#include "vector"
using namespace std;
int main() {
    string vvod;
    cin >> vvod;
    vector<int> mas(vvod.length());
    vector<int> vivid;
    mas[0] = 0;
    int j = 0;
    for (int i = 1; i < vvod.length(); i++) {
        j = mas[i - 1];
        while (j > 0 && vvod[j] != vvod[i]) {
            j = mas[j - 1];
        }
        if (vvod[j] == vvod[i]) {
            j++;
        }
        mas[i] = j;
        vivid.push_back(j);
    }
    cout << 0 << " ";
    for (auto i: vivid){
        cout << i << " ";
    }
    return 0;
}
