#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution{
private:
    set<pair<int, int>> bridges;
    int bridgesCount = 0;

    int32_t magic_hru_hru2(int f, int s, int n) {
        auto h1 = std::hash<int>{}(f);
        auto h2 = std::hash<int>{}(s);
        return ((n * h1 ^ h2)) + (n * h1 ^ h2) % 17;
    }

    void dfsCounting(vector<vector<int>> &graph,
                     int &v, int parent, int &timer,
                     vector<int> &tin,
                     vector<int> &up,
                     vector<int> &mark, unordered_map<int32_t, bool> &notToAdd, int n) {

        mark[v] = true;
        tin[v] = up[v] = timer++;
        for (auto i: graph[v]) {
            int to = i;
            if (to == parent) {
                continue;
            }
            if (mark[to]) {
                up[v] = min(up[v], tin[to]);
            } else {
                dfsCounting(graph, to, v, timer, tin, up, mark, notToAdd, n);
                up[v] = min(up[v], up[to]);
                if (up[to] > tin[v]) {

                    int32_t xorr1 = magic_hru_hru2(to, v, n);
                    int32_t xorr2 = magic_hru_hru2(v, to, n);
                    if (!(notToAdd[xorr1] and notToAdd[xorr2])) {
                        bridges.insert({to, v});
                        bridges.insert({v, to});
                        bridgesCount++;
                    }
                }
            }
        }
    }

    void dfsComp(int u, int prev, vector<vector<int>> &condensedGraph,
                 vector<int> &condensedGraphVisited, vector<int> &component,
                 int markingNum, vector<int> &numOfVertexInEachComp) {
        condensedGraphVisited[u] = true;
        component[u] = markingNum;
        numOfVertexInEachComp[component[u]]++;
        for (auto v: condensedGraph[u]) {
            if (!condensedGraphVisited[v] and v != prev) {
                dfsComp(v, u, condensedGraph, condensedGraphVisited, component, markingNum, numOfVertexInEachComp);
            }
        }
    }


    void dfs(int to, int from, vector<vector<int>> &graph,
             vector<int> &visited, vector<int> &dist, vector<int> &numOfVertexInEachComp,
             vector<int> &component, int &answer) {
        visited[to] = true;
        for (auto neighbor: graph[to]) {
            if (neighbor == from) {
                continue;
            }
            if (!visited[neighbor] and neighbor != from) {
                dfs(neighbor, to, graph, visited, dist, numOfVertexInEachComp, component, answer);
            }
            dist[to] += dist[neighbor];
        }
        answer += dist[to] * (numOfVertexInEachComp[component[to]] - dist[to]);
    }
public:
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<string, int> index;
        int n, m;
        cin >> n >> m;
        vector<int> tin(n, 0), up(n, 0);
        vector<int> mark(n, 0);
        vector<int> allVertexes(n);
        for (int i = 0; i < n; ++i) {
            string vertex;
            cin >> vertex;
            index[vertex] = i;
            allVertexes.push_back(i);
        }

        unordered_map<int32_t, bool> notToAdd(n);
        unordered_map<int32_t, bool> multiEdges(n);

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            string from, to;
            cin >> from >> to;
            int32_t xorr1 = magic_hru_hru2(index[from], index[to], n);
            int32_t xorr2 = magic_hru_hru2(index[to], index[from], n);
            if (!(multiEdges[xorr1] and multiEdges[xorr2])) {
                graph[index[from]].push_back(index[to]);
                graph[index[to]].push_back(index[from]);
                multiEdges[xorr1] = true;
                multiEdges[xorr2] = true;
            } else {
                notToAdd[xorr1] = true;
                notToAdd[xorr2] = true;
            }
        }


        int timer = 0;
        for (auto i: allVertexes) {
            if (!mark[i]) {
                int parent = -1;
                dfsCounting(graph, i, parent, timer, tin, up, mark, notToAdd, n);
            }
        }
        vector<vector<int>> condensedGraph(n);
        vector<int> dist(n);
        for (auto &[from, to]: bridges) {
            condensedGraph[from].push_back(to);
            dist[from] = 1;
        }
        vector<int> numOfVertexInEachComp(n, 0);
        vector<int> condensedGraphVisited(n, 0);
        vector<int> component(n, -1);
        int markingNum = 0;
        for (int i = 0; i < n; i++) {
            if (!condensedGraphVisited[i] and !condensedGraph[i].empty()) {
                dfsComp(i, -1, condensedGraph, condensedGraphVisited, component, markingNum, numOfVertexInEachComp);
                markingNum++;
            }
        }

        int answer = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i] and !condensedGraph[i].empty()) {
                int parent = -1;
                int r = i;
                dfs(r, parent, condensedGraph, visited, dist, numOfVertexInEachComp, component, answer);
            }
        }
        cout << answer;
    }
};


int main() {
    Solution a;
    a.solve();
    return 0;
}
