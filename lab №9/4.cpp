#include <iostream>
#include <vector>
#include <algorithm>
#include "set"

using namespace std;

int main() {
    unsigned long long N, M;
    cin >> N >> M;

    vector<vector<pair<unsigned long long, unsigned long long>>> graph(N);

    for (int i = 0; i < M; ++i) {
        unsigned long long x, y;
        unsigned long long l;
        cin >> x >> y >> l;
        x--;
        y--;
        graph[x].emplace_back(y, l);
        graph[y].emplace_back(x, l);
    }

    vector<vector<unsigned long long>> matrix(N);

    for (int i = 0; i < N; i++) {
        vector<unsigned long long> dist(N, ULONG_LONG_MAX);
        dist[i] = 0;

        set<pair<unsigned long long, int>> q;
        q.insert({dist[i], i});

        while (!q.empty()) {
            unsigned long long nearest = q.begin()->second;
            q.erase(q.begin());

            for (auto &[to, weight] : graph[nearest]) {
                if (dist[to] > dist[nearest] + weight && dist[nearest] != ULONG_LONG_MAX) {
                    q.erase({dist[to], to});
                    dist[to] = dist[nearest] + weight;
                    q.insert({dist[to], to});
                }
            }
        }
        matrix[i] = dist;
    }

    vector<unsigned long long> answers(N);
    unsigned long long min_elem = ULONG_LONG_MAX;

    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < N; j++){
            answers[i] += matrix[i][j];
        }

    }

    min_elem = answers[min_element(answers.begin(), answers.end()) - answers.begin()];

    for (int i = 0; i < answers.size(); i++){
        if (answers[i] == min_elem){
            cout << i + 1;
            return 0;
        }
    }

    return 0;
}
