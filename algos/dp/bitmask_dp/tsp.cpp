// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "tsp"

using namespace std;

const ll arr = 20, mod = 1e9 + 7;

ll cost[arr][arr], dp[1 << arr][arr];

ll tsp(int n){
    for (int mask = 1; mask < (1 << n); ++mask){
        for (int i = 0; i < n; ++i){
            dp[mask][i] = mod;
        }
    }
    dp[1][0] = 0;
    for (ll mask = 1; mask < (1 << n); ++mask){
        for (int u = 0; u < n; ++u){
            if (dp[mask][u] == mod) continue;
            for (int v = 0; v < n; ++v){
                if ((mask & (1 << v)) == 0){
                    ll nmask = mask | (1 << v);
                    dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + cost[u][v]);
                }
            }
        }
    }
    ll fmask = (1 << n) - 1, res = mod;
    for (int node = 1; node < n; ++node){
        res = min(res, dp[fmask][node] + cost[node][0]);
    }
    return (res == mod ? -1 : res);
}

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
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> cost[i][j];
        }
    }
    cout << tsp(n);
    return 0;
}