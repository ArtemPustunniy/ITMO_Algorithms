#include "iostream"
#include "vector"
#include "stack"

using namespace std;

class Solution{
private:
    int maxColor = 0;
    int time_ = 0;
    vector<vector<int>> adj;
    vector<int> tin, up, colors;
    stack<int> st;

    void paint(int v) {
        maxColor++;
        int last = -1;
        while (last != v && !st.empty()) {
            colors[st.top()] = maxColor;
            last = st.top();
            st.pop();
        }
    }

    void dfs(int v, int p) {
        time_++;
        st.push(v);
        tin[v] = time_;
        up[v] = time_;
        int children = 0;

        for (int u : adj[v]) {
            if (u == p) continue;
            if (tin[u] == 0) {
                children++;
                dfs(u, v);
                up[v] = min(up[v], up[u]);
                if (up[u] > tin[v]) {
                    paint(u);
                }
            } else {
                up[v] = min(up[v], tin[u]);
            }
        }

        if (p == -1 && children > 1) {
            paint(v);
        }
    }
    void solve(){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n, m, q;
        cin >> n >> m >> q;

        adj.resize(n + 2);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tin.assign(n + 2, 0);
        up.assign(n + 2, 0);
        colors.assign(n + 2, 0);

        for (int i = 0; i < n + 2; i++) {
            if (tin[i] == 0) {
                dfs(i, -1);
                paint(-1);
            }
        }

        for (int i = 0; i < q; i++){
            int start, end;
            cin >> start >> end;
            if (colors[start] == colors[end]){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }

        }
    }
public:
    void connect_solution(){
        solve();
    }
};


int main() {
    Solution a;
    a.connect_solution();
    return 0;
}
