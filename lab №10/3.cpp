#include "iostream"
#include "vector"
#include "queue"

using namespace std;

const long long INF = 1e9;

pair<vector<vector<pair<long long, long long>>>, long long> prim(long long n, vector<vector<pair<long long, long long>>>& adj) {
    vector<bool> visited(n, false);
    vector<long long> dist(n, INF);
    vector<long long> parent(n, -1);
    vector<vector<pair<long long, long long>>> mst(n);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;

    long long start = 0;
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        long long u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (auto edge : adj[u]) {
            long long v = edge.first;
            long long weight = edge.second;
            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    long long totalWeight = 0;
    for (long long i = 1; i < n; i++) {
        mst[i].emplace_back(parent[i], dist[i]);
        mst[parent[i]].emplace_back(i, dist[i]);
        totalWeight += dist[i];
    }

    return {mst, totalWeight};
}
 int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> adj(n);
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    auto result = prim(n, adj);
    vector<vector<pair<long long, long long>>> mst = result.first;
    long long totalWeight = result.second;

    cout << totalWeight << "\n";

    return 0;
}
