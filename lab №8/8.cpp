#include "iostream"
#include <vector>
#include "algorithm"
using namespace std;

void dfs(vector<int>& visited, int v, vector<vector<int>> &support, vector<int>& order) {
    visited[v] = 1;
    for(int to : support[v]) {
        if (!visited[to]) {
            dfs(visited, to, support, order);
        }
    }
    order.push_back(v);
}

void dfs1(vector<int>& visited, int v, int component, vector<vector<int>> &main) {
    visited[v] = component;
    for(int to : main[v]) {
        if (!visited[to]) {
            dfs1(visited, to, component, main);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, count;
    cin>> n >> m;
    if (n == 0){
        cout << "NO";
        return 0;
    }
    vector<vector<int>> main(2 * n) , support(2 * n);
    vector<int> visited, order;
    for (int i = 0; i < m; i ++) {
        string vvod;
        cin >> vvod;
        if (!isdigit(vvod[0])) {
            int left;
            left = stoi(&vvod[1]);
            left--;
            if (m == 1){
                cout << "NO";
                return 0;
            }
            main[2 * left + 1].push_back(2 * left);
            support[2 * left].push_back(2 * left + 1);
        }
        else {
            int left, right;
            left = stoi(vvod);
            left--;
            cin >> vvod;
            if (vvod == "->") {
                cin >> right;
                right--;
                main[2 * left + 1].push_back(2 * right + 1);
                support[2 * right + 1].push_back(2 * left + 1);
                main[2 * right].push_back(2 * left);
                support[2 * left].push_back(2 * right);
            }
            else if (vvod == "&") {
                cin >> right;
                right--;
                main[2 * left].push_back(2 * left + 1);
                support[2 * left + 1].push_back(2 * left);
                main[2 * right].push_back(2 * right + 1);
                support[2 * right + 1].push_back(2 * right);
            }
            else if (vvod == "||") {
                cin >> right;
                right--;
                main[2 * left].push_back(2 * right + 1);
                support[2 * right + 1].push_back(2 * left);
                main[2 * right].push_back(2 * left + 1);
                support[2 * left + 1].push_back(2 * right);
            }
            else if (vvod == "^") {
                cin >> right;
                right--;
                main[2 * left].push_back(2 * right + 1);
                support[2 * right + 1].push_back(2 * left);
                main[2 * right].push_back(2 * left + 1);
                support[2 * left + 1].push_back(2 * right);
                main[2 * left + 1].push_back(2 * right);
                support[2 * right].push_back(2 * left + 1);
                main[2 * right + 1].push_back(2 * left);
                support[2 * left].push_back(2 * right + 1);
            }
        }
    }
    visited.assign(main.size(), 0);
    for (int v = 0; v < main.size(); v++) {
        if(!visited[v]) {
            dfs(visited, v, support, order);
        }
    }
    reverse(order.begin(), order.end());
    visited.assign(main.size(), 0);

    for(int v : order) {
        if (!visited[v]){
            count++;
            dfs1(visited, v, count, main);
        }
    }
    bool flag = true;
    for(int i = 0; i < main.size() - 1; i++) {
        if (visited[i] == visited[i + 1]) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        cout<<"NO";
    } else {
        cout<<"YES";
    }

    return 0;
}

