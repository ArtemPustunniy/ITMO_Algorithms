#include "blazingio.hpp"

using namespace std;

int main() {
    int n;
    cin >> n;

    long long hashValue_1 = 0;
    long long hashValue_2 = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin>>x;
        hashValue_1 += x * x * x;

    }

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        hashValue_2 += x * x * x;
    }

    if (hashValue_1 == hashValue_2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
