#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;


const int INF = -1000010;

struct Edge {
    int u, v, weight;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[u] = v;
                if (rank[u] == rank[v]) {
                    rank[v]++;
                }
            }
        }
    }
};

vector<vector<pair<int, int>>> kruskal(int n, vector<Edge>& edges, int m) {
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(n);
    vector<vector<pair<int, int>>> mst(n);

    for (const Edge& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            mst[edge.u].emplace_back(edge.v, edge.weight);
            mst[edge.v].emplace_back(edge.u, edge.weight);

            ds.merge(edge.u, edge.v);
        }
    }
    ds.parent.clear();
    ds.rank.clear();
    return mst;

}

void dfs(int x, vector<int> &a, vector<int> &b, vector<int> &c, vector<vector<pair<int, int>>> &Ch, vector<bool> &visited) {
    visited[x] = true;
    for (auto i : Ch[x]) {
        if (!visited[i.first]){
            dfs(i.first, a, b, c, Ch, visited);
            a[x] = max(a[x], b[i.first] + i.second - c[i.first]);
            b[x] += c[i.first];
        }
    }
    a[x] += b[x];
    c[x] = max(a[x], b[x]);
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int m;
    int from, to, weight;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        from--;
        to--;
        edges[i].u = from;
        edges[i].v = to;
        edges[i].weight = weight;
    }

    auto result = kruskal(n, edges, m);

    std::vector<Edge> ().swap(edges);

    vector<int> a(n, 0);
    vector<int> b(n, 0);
    vector<int> c(n, 0);

    vector<bool> visited(n, false);

    dfs(0, a, b, c, result, visited);
    cout << c[0];

    return 0;
}
