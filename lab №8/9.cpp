#include "iostream"
#include <vector>
using namespace std;


void tipa_dfs(vector<vector<int>>& graph, vector<int>& visited, int v, int parent, bool &has_cycle) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (to == parent){
            continue;
        }
        else if (visited[to] == 0) {
            tipa_dfs(graph, visited, to, v, has_cycle);
        }
        else if (visited[to] == 1) {
            has_cycle = true;
        }
    }
    visited[v] = 2;
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> visited(n, false);
    vector<vector<int>> edges(n, std::vector<int>());
    vector<int> decs(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[b].push_back(a);
        edges[a].push_back(b);
        decs[a]++;
        decs[b]++;
    }
    bool has_cycle = false;
    tipa_dfs(edges, visited, 0, -1, has_cycle);
    if (has_cycle != m - (n - has_cycle) || !has_cycle ) {
        cout << "EUCLID";
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        if ( decs[i] != 1 &&  !visited[i]) {
            cout << "EUCLID";
            exit(0);
        }
    }
    cout << "ARCHIMEDES";
}
