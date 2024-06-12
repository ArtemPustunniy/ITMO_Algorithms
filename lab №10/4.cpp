#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(vector<vector<int>>& graph, int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(graph, v, visited);
        }
    }
}

//bool isConnected(vector<vector<int>>& graph, int n) {
//    vector<bool> visited(n, false);
//    dfs(graph, 0, visited);
//
//    for (int i = 0; i < n; i++) {
//        if (!visited[i]) {
//            return false;
//        }
//    }
//
//    return true;
//}

bool isEulerianCycle(vector<vector<int>>& graph, int n) {

    vector<bool> visited(n, false);
    dfs(graph, 0, visited);

    for (int i = 0; i < n; i++){
        if (!visited[i] && graph[i].size() > 0){
            return false;
        }
    }



    for (int i = 0; i < n; i++) {
        if (graph[i].size() % 2 != 0) {
            return false;
        }
    }

    return true;
}



void eulerianCycle(vector<vector<int>>& graph, int u, vector<int>& path, vector<int>& visited_euler) {
    while (!graph[u].empty()) {
        int v = graph[u][0];
        visited_euler[v] = 1;
        graph[u].erase(graph[u].begin());
        for (int i = 0; i < graph[v].size(); i++) {
            if (graph[v][i] == u) {
                graph[v].erase(graph[v].begin() + i);
                break;
            }
        }
        eulerianCycle(graph, v, path, visited_euler);
    }
    path.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> visited_euler(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (!isEulerianCycle(graph, n)) {
        cout << ":(";
        return 0;
    }

    vector<int> path;
    eulerianCycle(graph, 0, path, visited_euler);

    reverse(path.begin(), path.end());

    if (path.size() == 0){
        cout << ":(";
        return 0;
    }

    for (int vertex : path) {
        cout << vertex + 1 << " ";
    }

    return 0;
}
