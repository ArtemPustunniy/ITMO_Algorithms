# include "iostream"
# include "vector"
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited){
    visited[v] = 1;
    for (int to: graph[v]){
        if (!visited[to]){
            dfs(graph, to, visited);
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(N);
    vector<int> visited(N);
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);

    }
    int count = 0;

    for (int i = 0; i < edges.size(); i++){
        if (!visited[i]){
            dfs(edges, i, visited);
            count++;
        }
    }
    cout << count;

}
