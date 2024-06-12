#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int my_max = 1000;

    vector<int> xss(n, 0);
    vector<int> yss(n, 0);

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        xss[u - 1] += 1;
        xss[v - 1] += 1;
    }

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        yss[u - 1] += 1;
        yss[v - 1] += 1;
    }

    sort(xss.begin(), xss.end());
    sort(yss.begin(), yss.end());

    for (int i = 0; i < n; i++){
        if (xss[i] != yss[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";




    return 0;
}
