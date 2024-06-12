#include <iostream>
#include "vector"
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<int> & dist) {
    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.emplace(dist[start], start);
    while(!q.empty()) {
        auto [nearestDist, nearest] = q.top();
        q.pop();
        if (nearestDist != dist[nearest]){
            continue;
        }
        for (auto &[to, weight]: graph[nearest]){
            if (dist[to] > dist[nearest] + weight){
                dist[to] = dist[nearest] + weight;
                q.emplace(dist[to], to);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y, weight;
        cin >> x >> y >> weight;
        x--;
        y--;
        graph[x].emplace_back(y, weight);
    }
    vector<int> dist(n, INT_MAX);

    dijkstra(graph, 0, dist);

    if (dist[n - 1] != INT_MAX) {
        cout << dist[n - 1];
    }
    else {
        cout << -1;
    }

    return 0;
}

