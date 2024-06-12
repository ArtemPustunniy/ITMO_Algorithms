#include "blazingio.hpp"
#include <cstring>
#include "vector"
#include "algorithm"
using namespace std;

vector<pair<int, int>> answer;

bool wPrefersM1OverM(vector<vector<int>> &prefer, int w, int m, int m1, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
            return false;
    }
}

void stableMarriage(vector<vector<int>> &prefer, int n)
{
    int wPartner[n];

    bool mFree[n];

    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = n;

    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < n; m++)
            if (!mFree[m])
                break;

        for (int i = 0; i < n && !mFree[m]; i++)
        {
            int w = prefer[m][i];

            if (wPartner[w - n] == -1)
            {
                wPartner[w - n] = m;
                mFree[m] = true;
                freeCount--;
            }

            else
            {
                int m1 = wPartner[w - n];

                if (!wPrefersM1OverM(prefer, w, m, m1, n))
                {
                    wPartner[w - n] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        answer.emplace_back(wPartner[i], i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int count = 0;
    vector<vector<int>> prefer(2 * n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            prefer[i][j] = a + n;
            count++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            prefer[i + n][j] = a;
        }
    }
    stableMarriage(prefer, n);

    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i].first << " " << answer[i].second << "\n";
    }

    return 0;
}
