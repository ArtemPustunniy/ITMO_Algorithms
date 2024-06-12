#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    int* post;
    int* rang;
    vector<set<int>::iterator> mediana;
    vector<set<int>> fro_snm;
    vector<vector<int>> graph;
    int n;

    int get(int a) {
        if (post[a] == a) {
            return a;
        }
        return (post[a] = get(post[a]));
    }

    void connect(int a, int b) {
        a = get(a);
        b = get(b);
        if (rang[a] > rang[b])
            swap(a, b);
        rang[b] += rang[a];
        post[a] = b;
        for (auto i: fro_snm[a]) {
            int qw = fro_snm[b].size();
            fro_snm[b].insert(i);
            if (qw % 2 == 0 && i > *mediana[b]) {
                mediana[b]++;
            } else if (qw % 2 != 0 && i < *mediana[b]) {
                mediana[b]--;
            }
        }
    }

    void add_edge(){
        post = new int[n];
        rang = new int[n];
        fro_snm.resize(n);
        mediana.resize(n);
        graph.resize(n);
        for (int i = 0; i < n; i++) {
            post[i] = i;
            rang[i] = 1;
            fro_snm[i].insert(i + 1);
            mediana[i] = fro_snm[i].begin();
        }
    }

    void solve(){
        cin.tie(nullptr);
        int q;
        cin >> n >> q;
        add_edge();
        for (int i = 0; i < q; i++) {
            int command;
            cin >> command;
            if (command == 1) {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                graph[a].push_back(b);
                graph[b].push_back(a);
                if (get(a) == get(b)) {
                    continue;
                }
                connect(a, b);
            }
            else {
                int light;
                cin >> light;
                light--;
                cout << *mediana[get(light)] << "\n";
            }
        }
    }

public:
    void connect_solution(){
        solve();
    }
};


int main() {
    Solution a;
    a.connect_solution();
    return 0;
}
