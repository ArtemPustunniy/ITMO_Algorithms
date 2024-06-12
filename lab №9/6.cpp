#include "iostream"
#include "vector"

using namespace std;

struct Edge {
    int a, b, cost;
};

const int INF = 1000000000;

void bellman_ford(vector<Edge>& graph, int n, int len)
{
    vector<int> dist(n);
    vector<int> parent(n, -1);

//    dist[0] = 0;
    int x;

    for (int i = 0; i < n; i++)
    {
        x = -1;
        bool fl = false;
        for (Edge e : graph){
//            if (dist[e.a] < INF)
//            {
                if (dist[e.b] > dist[e.a] + e.cost)
                {
                    dist[e.b] = max(-INF, dist[e.a] + e.cost);
                    parent[e.b] = e.a;
                    x = e.b;

                    fl = true;
                }
//            }
        }

        if (!fl)
            break;
    }

    if (x == -1)
        cout << "YES" << "\n";
    else{
        int y = x;
        for (int i = 0; i < n; i++)
            y = parent[y];

        int count = 0;

        for (int v = y;; v = parent[v]) {
            ++count;
            if(v == y && count > 1) {
                break;
            }
        }

        if (count <= len)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}

int main(){

    int countgraph, len;

    cin >> countgraph >> len;

    for (int k = 0; k < countgraph; k++){
        int n, m;
        cin >> n >> m;

        vector<Edge> graph;
        for (int i = 0; i < m; i++){
            int x, y, weight;
            cin >> x >> y >> weight;
            graph.push_back({x - 1, y - 1, weight});
        }

        bellman_ford(graph, n, len);
    }
    return 0;
}
