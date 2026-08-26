// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1746"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr], dp[arr][106];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (a[1] == 0){
        for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    }
    else {
        dp[1][a[1]] = 1;
    }
    for (int i = 2; i <= n; ++i){
        if (a[i] == 0){
            for (int j = 1; j <= m; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
        }
        else dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % mod;
    }
    ll res = 0;
    for (int i = 1; i <= m; ++i) res = (res + dp[n][i]) % mod;
    cout << res;
    return 0;
}