#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct Node {
    int value;
    int low;
    int high;
};

bool BFS (int low, int high, vector<int> &distances, vector<vector<Node>> &graph) {
    queue<int> queue;
    fill(distances.begin(), distances.end(), 0);
    distances[0] = 1;
    queue.push(0);
    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        distances[vertex] = 1;
        for (auto to: graph[vertex]) {
            if (distances[to.value] == 0 && ((to.low <= low) && (high <= to.high))) {
                if (to.value == graph.size() - 1) {
                    return true;
                }
                distances[to.value] = 1;
                queue.push(to.value);
            }
        }
    }
    return false;
}


int main () {
    int n, m;
    cin >> n >> m;
    pair<int, int> pre_graph[m];
    pair<int, int> borders[m];
    vector<vector<Node>> graph(n);
    vector<int> visited(n, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        pre_graph[i] = make_pair(l, r);
//        cin >> pre_graph[i].first >> pre_graph[i].second;
    }

    for (int i = 0; i < m; i++) {
        int low, high;
        cin >> low >> high;
        borders[i] = make_pair(low, high);
        graph[pre_graph[i].first - 1].push_back({pre_graph[i].second - 1, borders[i].first, borders[i].second});
        graph[pre_graph[i].second - 1].push_back({pre_graph[i].first - 1, borders[i].first, borders[i].second});
    }

    bool flag = false;
    int maxcount = -1;
    int maxborder = 1e7;
    for (int i = 0; i < m; i++) {
        int left = borders[i].first;
        int right = maxborder;
        while (right > 1 + left) {
            int middle = left + (right - left) / 2;
            if (BFS(borders[i].first, middle, visited, graph)) {
                left = middle;
                flag = true;
            }
            else {
                right = middle;
            }
        }
        maxcount = max(maxcount, right - borders[i].first);
    }
    if (flag) {
        cout << maxcount;
    } else {
        cout << -1;
    }
}
