#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, int start, int K, vector<int>& distances) {
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (distances[to] == -1) {
                distances[to] = distances[v] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int N, M, K;
    cin >> N;
    cin >> M >> K;

    vector<vector<int>> edges(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int start = 0;
    vector<int> distances(N, -1);
    bfs(edges, start, K, distances);

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (distances[i] == K) {
            cout << i + 1 << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "NO";
    }

    return 0;
}

