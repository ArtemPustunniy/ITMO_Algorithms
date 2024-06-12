#include "iostream"
#include <queue>
#include <vector>

using namespace std;

struct tree {
    int x;
    int y;
    int z;
    int walk;

    tree(int x_, int y_, int z_, int walk_) {
        x = x_;
        y = y_;
        z = z_;
        walk = walk_;
    }
};

void bfs(int xs, int ys, int zs, int xf, int yf, int zf, int energy, vector<vector<vector<int>>> &ways, vector<vector<vector<bool>>> &graph){
    tree start(xs, ys , zs, 0);
    ways[start.x][start.y][start.z] = 0;
    int x_walk[] = {0,0,0,0,1,-1};
    int y_walk[] = {0, 0,1,-1,0,0};
    int z_walk[] = {1,-1,0,0,0,0};
    queue<tree> for_bfs;
    for_bfs.push(start);
    while(!for_bfs.empty()) {
        tree var = for_bfs.front();
        for_bfs.pop();
        if (var.walk > energy) {
            cout << -1;
            return;
        }
        if (ways[xf][yf][zf] != -1) {
            break;
        }
        for(int i = 0; i < 6; i++) {
            tree m(var.x + x_walk[i], var.y + y_walk[i],  var.z + z_walk[i], var.walk + 1);
            if ((!(m.x > 100 || m.x < 0 || m.y > 100 || m.y < 0 || m.z > 100 || m.z < 0 )) && graph[m.x][m.y][m.z] == 0 && ways[m.x][m.y][m.z] == -1) {
                ways[m.x][m.y][m.z] = m.walk;
                for_bfs.push(m);
            }
        }
    }
}

int main() {
    int n, energy, xs, ys, zs, xf, yf, zf;
    cin >> n >> energy;
    cin >> xs >> ys >> zs;
    cin >> xf >> yf >> zf;
    vector<vector<vector<bool>>> graph(110, vector<vector<bool>> (110, vector<bool> (110, false)));
    vector<vector<vector<int>>> ways(110, vector<vector<int>> (110, vector<int> (110, -1)));

    for (int i = 0; i < n; i++) {
        int x, y, z, h;
        cin >> x >> y >> z >> h;
        for (int j = z; j < (z + h); j++) {
            if (j < 110) {
                graph[x][y][j] = true;
            }
        }
    }

    if (xs == xf && ys == yf && zs == zf) {
        cout << 0;
        return 0;
    }

    if (energy == 0) {
        cout << -1;
        return 0;
    }

    bfs(xs, ys, zs, xf, yf, zf, energy, ways, graph);

    if (ways[xf][yf][zf] > energy || ways[xf][yf][zf] == -1) {
        cout << -1;
        return 0;
    }
    else{
        cout << ways[xf][yf][zf];
    }
    return 0;
}
