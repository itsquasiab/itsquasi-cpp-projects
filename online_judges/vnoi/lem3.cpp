// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "lem3"

using namespace std;

const ll arr = 20, mod = 1e9 + 7;

ll a[arr][arr], dp[65536][16];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    ll fullmask = (1 << n) - 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for (int mask = 0; mask <= fullmask; mask++){
        for (int k = 0; k < n; ++k){
            dp[mask][k] = 1e18;
        }
    }
    for (int i = 0; i < n; ++i){
        dp[1 << i][i] = 0;
    }
    for (int mask = 0; mask <= fullmask; mask++){
        for (int u = 0; u < n; ++u){
            if (dp[mask][u] == 1e18) continue;
            for (int v = 0; v < n; ++v){
                if ((mask & (1 << v) != 0)) continue;
                int newmask = mask | (1 << v);
                dp[newmask][v] = min(dp[newmask][v], dp[mask][u] + a[u][v]);
            }
        }
    }
    ll res = 1e18;
    for (int i = 0; i < n; ++i){
        res = min(res, dp[fullmask][i]);
    }
    cout << res;
    return 0;
}