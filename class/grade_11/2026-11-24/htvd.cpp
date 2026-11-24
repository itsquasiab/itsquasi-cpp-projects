// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#define ll long long
#define task "htvd"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr][arr];
ll dp[arr][arr];
pair<int, int> previous[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    dp[1][1] = a[1][1];
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == 1 && j == 1) continue;
            if (dp[i - 1][j] > dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j] + a[i][j];
                previous[i][j] = {i - 1, j};
            }
            else{
                dp[i][j] = dp[i][j - 1] + a[i][j];
                previous[i][j] = {i, j - 1};
            }
        }
    }
    int i = m, j = n;
    ll mx = max(0ll, a[1][1]);
    //cout << i << " " << j << "\n";
    while (i > 1 || j > 1){
        mx = max(mx, a[i][j]);
        pair<int, int> temp = previous[i][j];
        i = temp.first;
        j = temp.second;
        //cout << i << " " << j << "\n";
    }
    cout << dp[m][n] + mx;
    return 0;
}