#include "iostream"
#include "vector"
#include "queue"

using namespace std;

const int INF = 1e9;

pair<vector<vector<pair<int, int>>>, int> prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<bool> visited(n, false);
    vector<vector<pair<int, int>>> mst(n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int start = 0;
    pq.emplace(0, start);
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += w;

        for (auto edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                pq.emplace(edge.second, v);
            }
        }
    }

    return {mst, totalWeight};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    auto result = prim(n, adj);
    vector<vector<pair<int, int>>> mst = result.first;

    cout << result.second << "\n";

    return 0;
}
