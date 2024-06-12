#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int> vvod;
vector<int> vivod;

int main() {
    int N, max;
    int number;

    cin >> N >> max;
    for (int i = 0; i < N; i++) {
        cin >> number;
        vvod.push_back(number);
    }

    vivod.push_back(N);
    for (int i = 1; (2 * i - 1) < N; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (vvod[i + j] != vvod[i - j - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            vivod.push_back(N - i);
        }
    }
    reverse(vivod.begin(), vivod.end());
    for (auto elem: vivod){
        cout << elem << " ";
    }
    return 0;
}
