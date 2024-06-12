#include "iostream"
#include "vector"
using namespace std;




void dfs(int v, vector<vector<int>> &graph, vector<int> &parent) {
    for (int u : graph[v]) {
        if (u != parent[v]) {
            parent[u] = v;
            dfs(u, graph, parent);
        }
    }
}

vector<int> pruefer_code(vector<vector<int>> &graph, vector<int> &parent) {
    int n = graph.size();
    parent.resize(n);
    parent[n - 1] = -1;
    dfs(n - 1, graph, parent);

    int ptr = -1;
    vector<int> degree(n);
    for (int i = 0; i < n; i++) {
        degree[i] = graph[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }

    vector<int> code(n - 2);
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++) {
        int next = parent[leaf];
        code[i] = next;
        if (--degree[next] == 1 && next < ptr) {
            leaf = next;
        } else {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }

    return code;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> parent;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    vector<int> code = pruefer_code(adj, parent);

    for (int i = 0; i < code.size(); i++) {
        cout << code[i] + 1 << " ";
    }

    return 0;
}
