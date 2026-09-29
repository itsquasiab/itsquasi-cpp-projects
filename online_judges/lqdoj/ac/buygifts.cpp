// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "buygifts"

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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a + 1, a + 1 + n);
    ll res = 1e18;
    for (int i = m; i <= n; ++i){
        res = min(res, a[i] - a[i - m + 1]);
        //cout << a[i] << " " << a[i - m + 1] << " " << a[i] - a[i - m + 1] << "\n";
    }
    cout << res;
    return 0;
}