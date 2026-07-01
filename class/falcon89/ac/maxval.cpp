// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "maxval"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

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
    ll mx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a + 1, a + 1 + n);
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        for (int k = 2 * a[i]; k <= mx + a[i]; k += a[i]){
            auto j = lower_bound(a + 1, a + 1 + n, k);
            if (j != a + 1) {
                ll aj = *(--j);
                if (aj >= a[i]){
                    res = max(res, aj % a[i]);
                }
            }
        }
    }
    cout << res;
    return 0;
}