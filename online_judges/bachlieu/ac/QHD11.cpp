//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr][arr];
ll dp[arr][arr];
ll trace[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i){
        dp[1][i] = a[1][i];
        trace[1][i] = -1;
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            ll best = dp[i - 1][j];
            ll prev = j;
            if (j > 1 && dp[i - 1][j - 1] > best){
                best = dp[i - 1][j - 1];
                prev = j - 1;
            }
            if (j < m && dp[i - 1][j + 1] > best){
                best = dp[i - 1][j + 1];
                prev = j + 1;
            }
            dp[i][j] = best + a[i][j];
            trace[i][j] = prev;
        }
    }
    ll res = 0;
    int pos = 0;
    for (int i = 1; i <= m; ++i){
        if (dp[n][i] > res){
            res = dp[n][i];
            pos = i;
        }
    }
    cout << res << "\n";
    vector<int> path;
    int row = n, col = pos;
    while (row > 0){
        path.push_back(col);
        col = trace[row][col];
        row--;
    }
    reverse(path.begin(), path.end());
    for (auto c : path){
        cout << c << "\n";
    }
    return 0;
}