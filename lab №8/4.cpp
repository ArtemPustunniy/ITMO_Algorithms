#include "iostream"
#include <vector>
#include <set>
#include "algorithm"
using namespace std;


void dfs(int v, vector<int>& visited, vector<vector<int>> &support, vector<int>& order) {
    visited[v] = 1;
    for(int to : support[v]) {
        if (!visited[to]) {
            dfs(to, visited, support, order);
        }
    }
    order.push_back(v);
}
void dfs1(int v, int component, vector<int>& visited, vector<vector<int>> &main) {
    visited[v] = component;
    for(int to : main[v]) {
        if (!visited[to]) {
            dfs1(to, component, visited, main);
        }
    }
}

void dfs_task(int v, int *counter, std::vector<int> & min_point, vector<int>& visited, vector<int>& visited2, set<pair<int, int>> &answer, vector<vector<int>> &support) {
    visited2[v] = 1;
    for (int to : support[v]) {
        if (visited[v] != visited[to]) {
            pair<int, int> a(min_point[visited[to] - 1], min_point[visited[v] - 1]);
            answer.insert(a);
            *counter += 1;
        }
        if(!visited2[to]) {
            dfs_task(to,  counter, min_point, visited, visited2, answer, support);
        }
    }
}

void findScc(vector<int>& visited, vector<int>& visited2, set<pair<int, int>> &answer, vector<vector<int>> &main, vector<vector<int>> &support, vector<int>& order) {
    visited.assign(main.size(), 0);
    for (int v = 0; v < main.size(); v++) {
        if(!visited[v]) {
            dfs(v, visited, support, order);
        }
    }
    reverse(order.begin(), order.end());
    visited.assign(main.size(), 0);
    int sc_count = 0;
    for(int v : order) {
        if (!visited[v]){
            dfs1(v, ++sc_count, visited, main);
        }
    }
    vector<int> min_point(sc_count, -2);
    for (int i = 0; i < visited.size(); i++) {
        if(min_point[visited[i] - 1] == -2) {
            min_point[visited[i] - 1] = i;
        }
    }
    visited2.assign(main.size(), 0);
    int counter = 0;
    for(int v : order) {
        if (!visited2[v]){
            dfs_task(v, &counter, min_point, visited, visited2, answer, support);
        }
    }
    cout<<sc_count<<" "<<answer.size()<<"\n";
    for(auto to : answer) {
        cout<<to.first + 1<<" "<<to.second + 1<<"\n";
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin>> n >> m;
    vector<vector<int>> main(n) , support(n);
    vector<int> visited, visited2,  order;
    vector<vector<int>> reb;
    set<pair<int, int>> answer;
    for (int i = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        main[a - 1].push_back(b - 1);
        support[b - 1].push_back(a - 1);
    }
    findScc(visited, visited2, answer, main, support, order);

    return 0;
}
