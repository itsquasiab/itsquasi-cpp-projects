// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "choose"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr][arr];

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
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    ll res = -1e18;
    for (int i1 = 1; i1 <= n; ++i1){
        for (int i2 = i1 + 1; i2 <= n; ++i2){
            ll mx1 = -1e18;
            ll mx2 = -1e18;
            for (int j = 1; j <= m; ++j){
                ll val = a[i1][j] + a[i2][j];
                if (val >= mx1){
                    mx2 = mx1;
                    mx1 = val;
                }
                else if (val > mx2){
                    mx2 = val;
                }
            }
            res = max(res, mx1 + mx2);
        }
    }
    cout << res;
    return 0;
}