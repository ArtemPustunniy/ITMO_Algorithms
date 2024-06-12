#include <iostream>
#include <vector>



using namespace std;



bool dfs(int i, vector<bool> &visited, vector<vector<int>> &matrix, vector<int> &matching) {
    if (visited[i]) {
        return false;
    }

    visited[i] = true;

    for (int to : matrix[i]) {
        if (matching[to] == -1 || dfs(matching[to], visited, matrix, matching)) {
            matching[to] = i;
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n,vector<int>(m, 1));
    vector<bool> visited;

    int k1 = 0;
    int k2 = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) % 2 != 0) {
                graph[i][j] = k1;
                k1++;
            }
            else {
                graph[i][j] = k2;
                k2++;
            }
        }
    }



    int max = INT_MAX;

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = max;
    }

//    for (int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << graph[i][j] << " ";
//        }
//        cout << "\n";
//    }


    vector<vector<int>> matrix(k1,vector<int>(0, 0));
    int qw = std::max(k1, k2);
    vector<int> matching(qw,-1);


    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] != max) {
                if((i + j) % 2 != 0) {
                    if(j > 0 && graph[i][j - 1] != max) {
                        matrix[graph[i][j]].push_back(graph[i][j - 1]);
                    }
                    if(i > 0 && graph[i - 1][j] != max) {
                        matrix[graph[i][j]].push_back(graph[i - 1][j]);
                    }
                    if(i < n - 1 && graph[i + 1][j] != max) {
                        matrix[graph[i][j]].push_back(graph[i + 1][j]);
                    }
                    if(j < m - 1 && graph[i][j + 1] != max) {
                        matrix[graph[i][j]].push_back(graph[i][j + 1]);
                    }
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < matrix.size(); i++){
        visited.assign(n * m + 1,false);
        if(dfs(i, visited, matrix, matching)){
            answer++;
        }
    }
    answer *= 2;


    cout << answer;

}

