#include "blazingio.hpp"
#include "string"
#include "vector"
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string vvod;
    cin >> vvod;
    vector<int> positions;
    int result = 0;
    int i, j, k;
    for (int s = 0; s < M; s++) {
        cin >> i >> j >> k;
        if (vvod.substr(i - 1, k) == vvod.substr(j - 1, k)) {
            result++;
        }
    }
    cout << result;
    return 0;
}
