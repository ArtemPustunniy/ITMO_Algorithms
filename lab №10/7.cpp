#include "iostream"
#include "vector"
#include "algorithm"


using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rang;
    int size;

    DSU(int _size) {
        size = _size;
        parent.resize(size);
        rang.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rang[i] = 1;
        }
    }

    int find(int v) {
        if (parent[v] == v) {
            return v;
        } else {
            parent[v] = find(parent[v]);
            return parent[v];
        }
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (rang[a] < rang[b])
            swap(a, b);
        parent[b] = a;
        if (rang[a] == rang[b]) {
            rang[a] += 1;
        }
    }
};

class edge {
public:
    int from;
    int to;
    int weight;

    edge(int _f, int _t, int _w) {
        from = _f;
        to = _t;
        weight = _w;
    }

    bool operator<(const edge &other) const {
        return this->weight < other.weight;
    }

    bool operator>(const edge &other) const {
        return this->weight > other.weight;
    }
};

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> edges;
    DSU dsu(n);
    long long luckySum = 0;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from--;
        to--;
        edge e = edge(from, to, weight);
        luckySum += weight;
        edges.push_back(e);
    }
    for (int i = 0; i < k; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from--;
        to--;
        edge e = edge(from, to, weight);
        edges.push_back(e);
    }

    long long mstSum = 0;
    vector<vector<int>> graph(n);
    sort(edges.begin(), edges.end());

    for (auto &[f, t, w]: edges) {
        if (dsu.find(f) != dsu.find(t)) {
            dsu.unite(f, t);
            mstSum += w;
        }
    }

    if (mstSum - luckySum >= 0) {
        cout << mstSum - luckySum;
    } else {
        cout << 0;
    }
}
