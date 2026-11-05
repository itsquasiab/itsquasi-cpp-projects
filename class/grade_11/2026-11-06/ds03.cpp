// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "ds03"

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
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll res = 0;
    sort (a + 1, a + 1 + n);
    for (int i = 3; i <= n; ++i){
        for (int j = 2; j < i; ++j){
            ll calc = j - (lower_bound(a + 1, a + j + 1, a[i] - a[j] + 1) - a);
            //cout << i << " " << j << " " << (lower_bound(a + 1, a + j + 1, a[i] - a[j] + 1) - a) << "\n";
            res += max(0ll, calc);
        }
    }
    cout << res;
    return 0;
}