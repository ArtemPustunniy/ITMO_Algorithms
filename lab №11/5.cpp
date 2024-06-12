#include "iostream"
# include <algorithm>
# include <cstring>
# include <vector>

using namespace std;

const int N_MAX = 2001;

struct Edge
{
    int to, next;
};

int n, m, e;
vector <int> g[N_MAX + 10];

int opp[N_MAX + 10];
bool vis[N_MAX + 10];

bool vx[N_MAX + 10], vy[N_MAX + 10];

void addEdge(int x, int y)
{
    g[x].push_back(y);
}

bool find(int x){
    if (vis[x]) return false;
    vis[x] = true;
    for (int i = 0; i < (int) g[x].size(); i++) {
        int y = g[x][i];
        if (opp[y] == 0 || find(opp[y])) {
            opp[y] = x;
            return true;
        }
    }
    return false;
}

void mark(int x){
    if (vx[x]) return;
    vx[x] = true;
    for (int i = 0; i < (int) g[x].size(); i++) {
        int y = g[x][i];
        if (opp[y] && !vy[y]) {
            vy[y] = true;
            mark(opp[y]);
        }
    }
}

int hungary(){
    memset(opp, 0, sizeof(opp));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        ans += find(i);
    }
    return ans;
}

int konig()
{
    int ans = hungary();
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= m; i++)
        vis[opp[i]] = true;
    memset(vx, false, sizeof(vx));
    memset(vy, false, sizeof(vy));
    for (int i = 1; i <= n; i++)
        if (!vis[i]) mark(i);
    return ans;
}

int main()
{
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
    }
    konig();
    vector<int> left;
    vector<int> right;

    for (int i = 1; i <= n; i++)
        if (!vx[i]){
            left.push_back(i);
        }
    for (int i = 1; i <= m; i++)
        if (vy[i]){
            right.push_back(i);
        }
    cout << left.size() << "\n";
    for (int i: left){
        cout << i << "\n";
    }
    if (left.empty()){
        cout << "\n";
    }
    cout << right.size() << "\n";
    for (int i: right){
        cout << i << "\n";
    }
    return 0;
}
