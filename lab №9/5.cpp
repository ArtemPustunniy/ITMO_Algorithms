#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> visited;
    vector<pair<int, int>> answer;
    vector<int> tin, low;
    int timer = 0;

    void dfs(int v, int p = -1) {
        visited[v] = 1;
        tin[v] = low[v] = timer++;
        for (int to : graph[v]) {
            if (to == p){
                continue;
            }
            if (!visited[to]) {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] > tin[v] && v < to) {
                    answer.emplace_back(v, to);
                }
                if (low[to] > tin[v] && v >= to){
                    answer.emplace_back(to, v);
                }
            }
            else {
                low[v] = min(low[v], tin[to]);
            }
        }
    }

    void solve(){
        int n, m;
        cin >> n >> m;

        graph.resize(n);

        for (int i = 0; i < m; ++i) {
            int a, b;
            std::cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        visited.assign(n, 0);
        tin.assign(n, -1);
        low.assign(n, -1);
        timer = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size() - 1 && !answer.empty(); i++) {
            cout << answer[i].first + 1 << " " << answer[i].second + 1 << "\n";
        }
        if (!answer.empty()) {
            cout << answer[answer.size() - 1].first + 1 << " " << answer[answer.size() - 1].second + 1;
        }
    }
public:
    void connect_sove(){
        solve();
    }
};


int main() {
    Solution a;
    a.connect_sove();
    return 0;
}
