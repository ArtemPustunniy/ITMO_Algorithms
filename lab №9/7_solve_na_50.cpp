#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"

using namespace std;

const long long INF = 2e18;

struct Verticles {
    long long final_count;
    long long soldiers;
};

struct DP_s {
    long long cc;
    long long minimal;
    Verticles verts;

};

bool operator<(const Verticles &x, const Verticles &y) {
    if (x.final_count != y.final_count) return x.final_count < y.final_count;
    return x.soldiers > y.soldiers;
}

bool operator>(const DP_s &x, const DP_s &y) {
    return !(tie(x.verts, x.cc, x.minimal) < tie(y.verts, y.cc, y.minimal));
}

class Solution{
private:
    void solve() {
        int n, m, p;
        cin >> n >> m >> p;
        vector<vector<pair<long long, long long>>> g(n, vector<pair<long long, long long>>(n, {0, INF}));
        vector<long long> w(n);
        vector dp(n, vector<Verticles>(n, {INF, 0}));
        priority_queue<DP_s, vector<DP_s>, greater<>> pq;
        pq.push({ .cc = 0, .minimal=0, .verts = {.final_count=0, .soldiers=p}});
        dp[0][0] = {0, p};

        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            long long s;
            cin >> a >> b >> s;
            a--;
            b--;
            g[a].emplace_back(b, s);
        }

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            long long v = current.cc;
            long long best = current.minimal;
            if (!((dp[v][best].final_count == current.verts.final_count) && (dp[v][best].soldiers == current.verts.soldiers))){
                continue;
            }
            for (auto &[u, s]: g[v]) {
                auto temp = current;
                Verticles &going = temp.verts;
                if (going.soldiers < s) {
                    long long need = (s - going.soldiers + w[best] - 1) / w[best];
                    going.final_count += need;
                    going.soldiers += need * w[best];
                }
                temp.cc = u;
                going.soldiers -= s;
                if (w[u] > w[temp.minimal]){
                    temp.minimal = u;
                }
                if (going < dp[u][temp.minimal]) {
                    dp[u][temp.minimal] = going;
                    pq.push(temp);
                }
            }
        }
        long long answer = INF;
        for (int i = 0; i < n; i++){
            answer = min(answer, dp[n - 1][i].final_count);
        }

        if (answer != INF){
            cout << answer << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
public:
    void connect_solution(){
        solve();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution a;
    a.connect_solution();
    return 0;
}
