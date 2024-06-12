#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int v, vector<int>& answer, int& this_point) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to]) {
            dfs(graph, visited, to, answer, this_point);
        }
    }
    answer[v] = this_point--;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edge(N);
    vector<int> answer(N);
    vector<int> visited(N);
    int current = N - 1;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(edge, visited, i, answer, current);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] + 1 << " ";
    }

    return 0;
}
