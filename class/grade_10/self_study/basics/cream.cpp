// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "cream"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr], b[arr], d[arr];

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
    for (int i = 1; i <= n; ++i) cin >> b[i];
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        d[i] = a[i] - b[i];
    }
    sort (d + 1, d + 1 + n, greater<ll>());
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        sum += d[i];
        if (sum <= 0) break;
        res++;
    }
    cout << res;
    return 0;
}