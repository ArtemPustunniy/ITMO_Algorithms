#include "iostream"
#include "vector"

using namespace std;

int del = 1e9 + 7;

vector<vector<int>> pole;

long long first_cord = 0;
long long second_cord = 0;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    pole.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pole[i][j];
        }
    }

    int q;
    cin >> q;
    int x1, y1, x2, y2, x3, y3, x4, y4;

    for (int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        cin >> x3 >> y3 >> x4 >> y4;
        x3--;
        x4--;
        y3--;
        y4--;

        if (x1 == x3 && x2 == x4 && y1 == y3 && y2 == y4) {
            cout << "YES" << "\n";
            continue;
        }

        int result = 1;
        int i1 = x1, i2 = x3;
        while (i1 <= x2) {
            int j1 = y1, j2 = y3;
            while (j1 <= y2) {
                if (pole[i1][j1] != pole[i2][j2]) {
                    result = 0;
                    break;
                }
                j1++;
                j2++;
            }
            i1++;
            i2++;
        }

        if (result)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

    }

    return 0;
}
