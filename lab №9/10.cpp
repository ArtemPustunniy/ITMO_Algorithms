#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

class Solution{
private:
    int n, m, q;
    char command;
    vector<char> commands;
    vector<int> nums;
    vector<string> ans;
    vector<vector<int>> graph;
    int* post;
    int* rang;

    int get(int a){
        if (a == post[a])
            return a;
        return (post[a] = get(post[a]));
    }

    void connect(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b) {
            if (rang[a] > rang[b]) swap(a, b);
            rang[b] += rang[a];
            post[a] = b;
        }
    }

    void add_edge(){
        cin >> n >> m >> q;
        graph.resize(n);
        post = new int[n];
        rang = new int[n];

        for (int i = 0; i < n; i++) {
            post[i] = i;
            rang[i] = 0;
            graph.emplace_back();
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> command >> a >> b;
            a--;
            b--;

            commands.push_back(command);
            nums.push_back(a);
            nums.push_back(b);

            if (command == '-') {
                for (int j = 0; j < graph[a].size(); j++) {
                    if (graph[a][j] == b) {
                        graph[a].erase(graph[a].begin() + j);
                    }
                }
                for (int j = 0; j < graph[b].size(); j++) {
                    if (graph[b][j] == a) {
                        graph[b].erase(graph[b].begin() + j);
                    }
                }
            }
        }
    }

    void solve() {
        add_edge();
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                connect(i, graph[i][j]);
            }
        }

        int k = nums.size() - 1;
        for (int i = q - 1; i >= 0; i--) {
            if (commands[i] == '?') {
                if (get(nums[k - 1]) == get(nums[k])) {
                    ans.emplace_back("YES");
                }
                else {
                    ans.emplace_back("NO");
                }
            }
            else {
                connect(nums[k - 1], nums[k]);
            }
            k = k - 2;
        }

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << '\n';
        }
    }

public:
    void connect_solution(){
        solve();
    }
};


int main() {
    Solution a;
    a.connect_solution();
    return 0;
}
