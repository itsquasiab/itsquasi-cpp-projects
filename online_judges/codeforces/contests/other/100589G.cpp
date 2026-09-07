// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "100589G"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        ll dp[1 << n][n + 1];
        for (ll mask = 0; mask < (1 << n); ++mask){
            for (int i = 0; i <= n; ++i) dp[mask][i] = 0;
        }
        dp[0][0] = 1;
        for (ll mask = 0; mask < (1 << n); ++mask){
            for (int q = 1; q <= n; ++q){
                if (!((mask >> (q - 1)) & 1)){
                    for (int p = 0; p <= n; ++p){
                        if (p != 0 && abs(q - p) > k) continue;
                        ll nmask = mask | (1 << (q - 1));
                        dp[nmask][q] += dp[mask][p];
                    }
                }
            }
        }
        ll res = 0;
        for (int i = 1; i <= n; ++i){
            res += dp[(1 << n) - 1][i];
        }
        cout << res << "\n";
    }
    return 0;
}