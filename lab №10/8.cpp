#include "iostream"
#include "vector"
#include "queue"

using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int t, s;
        cin >> t >> s;
        vector<int> vertices(t);
        for (int j = 0; j < t; j++) {
            cin >> vertices[j];
        }
        for (int j = 0; j < t; j++) {
            for (int q = j; q < t; q++){
                if (j != q){
                    adj[vertices[j]].push_back({vertices[q], s});
                    adj[vertices[q]].push_back({vertices[j], s});
                }
            }

        }
        vertices.clear();
    }
//    for (int i = 0; i < adj.size(); i++){
//        cout << i + 1 << " --- ";
//        for (int j = 0; j < adj[i].size(); j++){
//            cout << adj[i][j].to << " ";
//        }
//        cout << "\n";
//    }

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge e : adj[u]) {
            if (dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    if (dist[k] == INT_MAX) {
        cout << -1;
    } else {
        cout << dist[k];
    }

    return 0;
}
