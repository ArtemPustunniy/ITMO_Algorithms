#include "blazingio.hpp"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<int> for_answer(n, 0);
    int color = 1;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
        if (for_answer[a] == 0){
            for_answer[a] = color;
            color++;
        }
        if (for_answer[b] == 0){
            for_answer[b] = color;
            color++;
        }
    }
    deque<int> order;
    for (int i = 0; i < n; ++i)
        order.push_back(i);

    for (int i = 0; i < n * (n - 1); ++i) {
        if (!graph[order[0]][order[1]]) {
            int k = 2;
            while (!graph[order[0]][order[k]] || !graph[order[1]][order[k + 1]])
                k++;
            reverse(order.begin() + 1, order.begin() + k);
        }
        order.push_back(order.front());
        order.pop_front();
    }

    vector<pair<int, int>> print_answer;

    for (int i = 0; i < order.size(); i++){
        print_answer.push_back({for_answer[order[i]], order[i]});
    }
    sort(print_answer.begin(), print_answer.end());

    for (int i = 0; i < print_answer.size(); i++){
        cout << print_answer[i].second << " ";
    }

}
