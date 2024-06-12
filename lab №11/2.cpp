#include "iostream"
#include "vector"

using namespace std;

int inf = INT_MAX;

int dfs(vector<vector<int>> &graph, vector<vector<int>> &flow, int u, int cmin, int visited[], int end, int N) {
    if (u == end) {
        return cmin;
    }
    visited[u] = 1;
    for (int i = 0; i < N; i++) {
        if ((visited[i] == -1) and (flow[u][i] < graph[u][i])) {
            int diff = dfs(graph, flow, i, min(cmin, (graph[u][i] - flow[u][i])), visited, end, N);
            if (diff > 0) {
                flow[u][i] += diff;
                flow[i][u] -= diff;
                return diff;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    int u, v, c, maxc = 0;
    cin >> N >> M;
    vector <vector <int>> graph(N, vector <int>(N, 0));
    vector <vector <int>> flow(N, vector <int>(N, 0));
    vector<vector<int>> adj_list;
    adj_list.resize(N);
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        u--;
        v--;
        graph[u][v] = c;
    }
    int visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = -1;
    }
    while (int cur = dfs(graph, flow, 0, inf, visited, N - 1, N)) {
        maxc += cur;
        for (int i = 0; i < N; i++) {
            visited[i] = -1;
        }
    }
    cout << maxc;
    return 0;
}
