#include "blazingio.hpp"
#include "vector"
#include "queue"

using namespace std;

static int flow = 0;
static int cost = 0;
const int INF = 1000000000;

struct Edges {
    int to;
    int capacity;
    int cost;
    int flow;
    int rev;

    Edges(int to_, int capacity_, int cost_, int flow_, int reverse_){
        to = to_;
        cost = cost_;
        rev = reverse_;
        capacity = capacity_;
        flow = flow_;
    }

};


int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<Edges>> graph(n + 1);
    vector<int> dist(n + 1);
    vector<int> prev_vertex(n + 1);
    vector<int>prev_edge(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, c, p;
        cin >> u >> v >> c >> p;
        int from_size = graph[u].size();
        int to_size = graph[v].size();


        graph[v].emplace_back(u, 0, -p, 0, from_size);
        graph[u].emplace_back(v, c, p, 0, to_size);

    }

    for(;;) {
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, s);

        while (!pq.empty()) {
            int cur_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dist[u] < cur_dist)
                continue;

            for (int i = 0; i < graph[u].size(); ++i) {
                Edges& e = graph[u][i];
                if (e.capacity - e.flow > 0 && dist[e.to] > dist[u] + e.cost) {
                    dist[e.to] = dist[u] + e.cost;
                    prev_vertex[e.to] = u;
                    prev_edge[e.to] = i;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }

        if (dist[t] == INF)
            break;

        int aug_flow = INF;
        int cur = t;
        while (cur != s) {
            Edges& e = graph[prev_vertex[cur]][prev_edge[cur]];
            aug_flow = min(aug_flow, e.capacity - e.flow);
            cur = prev_vertex[cur];
        }

        cur = t;

        flow += aug_flow;

        while (cur != s) {
            Edges& e = graph[prev_vertex[cur]][prev_edge[cur]];
            e.flow += aug_flow;
            graph[cur][e.rev].flow -= aug_flow;
            cost += e.cost * aug_flow;
            cur = prev_vertex[cur];
        }
    }

    cout << flow << " " << cost << "\n";

    return 0;
}
