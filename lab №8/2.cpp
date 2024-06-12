#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int>& visited, int a, int b) {
    if (a == b) {
        return true;
    }

    for (int to : graph[a]) {
        if (!visited[to]) {
            visited[to] = 1;
            if (dfs(graph, visited, to, b)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> edges(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> visited(N, 0);
        a--;
        b--;

        bool answer = false;

        visited[a] = 1;

        if (dfs(edges, visited, a, b)) {
            fill(visited.begin(), visited.end(), false);
            visited[b] = 1;

            answer = dfs(edges, visited, b, a);
        }


        if (answer) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }


    return 0;
}
