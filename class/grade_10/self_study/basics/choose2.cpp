// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "choose2"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr][arr], col[arr], pf[arr];

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
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    ll res = -1e18;
    for (int i1 = 1; i1 <= m; ++i1){
        for (int j = 1; j <= n; ++j) col[j] = a[i1][j];
        for (int i2 = i1 + 1; i2 <= m; ++i2){
            for (int j = 1; j <= n; ++j){
                col[j] += a[i2][j];
                ll b = a[i1][j] + a[i2][j];
                pf[j] = pf[j - 1] + b;
            }
            ll best = -1e18;
            for (int c2 = 2; c2 <= n; ++c2){
                int c1 = c2 - 1;
                best = max(best, col[c1] - pf[c1]);
                ll cur = best + col[c2] + pf[c2 - 1];
                res = max(res, cur);
            }
        }
    }
    cout << res;
    return 0;
}