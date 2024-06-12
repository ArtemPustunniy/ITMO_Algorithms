#include <bits/stdc++.h>

using namespace std;

int post[5000];

int get(int a){
    if (a == post[a])
        return a;
    return (post[a] = get(post[a]));
}

void connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        post[a] = b;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> graph;
    long long answer1 = 0;
    long long answer2 = LONG_LONG_MAX;
    for (int i = 0; i < n; i++){
        post[i] = i;
    }

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end());

    vector<int> connects;
    for (int i = 0; i < graph.size(); i++){
        int q = get(graph[i].second.first);
        int z = get(graph[i].second.second);
        if (q != z){
            post[q] = z;
            answer1 += graph[i].first;
            connects.push_back(i);
        }
    }

    for (auto j: connects){
        for (int i = 1; i <= n; i++){
            post[i] = i;
        }
        long long now_ans = 0;
        int counter = 0;
        for (int i = 0; i < graph.size(); i++){
            if (i == j){
                continue;
            }
            int q = get(graph[i].second.first);
            int z = get(graph[i].second.second);
            if (q != z){
                post[q] = z;
                now_ans += graph[i].first;
                counter++;
            }
        }
        if (counter == n - 1){
            answer2 = min(answer2, now_ans);
        }
    }
    cout << answer1 << " " << answer2 << "\n";



}
