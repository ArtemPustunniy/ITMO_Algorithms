#include <iostream>
#include <vector>

using namespace std;


void dfs(int u, int v, vector<vector<int>> &graph, vector<int> &visited) {
    visited[u] = 1;

    for (int to: graph[u]) {
        if (!visited[to]) {
            dfs(to, v, graph, visited);
        }
    }
}

int main() {
    cin.tie(nullptr);
    int N, M, Q;
    char command;

    cin >> N >> M >> Q;

    vector<vector<int>> graph(N);
    vector<int> visited(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> command;
        cin >> x >> y;
        x--;
        y--;

        if (command == '?') {
            dfs(x, y, graph, visited);
            if (visited[y]) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
            visited.assign(N, 0);
        } else {
            for (int j = 0; j < graph[x].size(); j++) {
                if (graph[x][j] == y) {
                    graph[x].erase(graph[x].begin() + j);
                }
            }
            for (int j = 0; j < graph[y].size(); j++) {
                if (graph[y][j] == x) {
                    graph[y].erase(graph[y].begin() + j);
                }
            }
        }
    }
}
