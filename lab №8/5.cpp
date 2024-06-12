#include <iostream>
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

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(N);
    vector<int> visited(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bool has_cycle = false;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            tipa_dfs(edges, visited, i, -1, has_cycle);
        }
    }
    if (has_cycle){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}

