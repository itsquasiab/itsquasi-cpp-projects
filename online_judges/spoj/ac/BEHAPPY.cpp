// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#define ll long long
#define task "BEHAPPY"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

pair<int, int> a[arr];
ll dp[arr][arr];

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
    ll mx = 0;
    for (int i = 1; i <= m; ++i){
        cin >> a[i].first >> a[i].second;
        mx += a[i].second;
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= mx; ++j){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i){
        for (int j = 0; j <= n; ++j){
            for (int k = a[i].first; k <= a[i].second; ++k){
                if (j - k >= 0) dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    cout << dp[m][n];
    return 0;
}