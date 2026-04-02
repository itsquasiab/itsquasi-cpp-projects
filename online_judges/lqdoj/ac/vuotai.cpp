// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "vuotai"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], pf[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    ll res = pf[n];
    for (int i = 1; i <= n; ++i){
        ll exp = (pf[i - 1] + (pf[n] - pf[i]) + max(0ll, a[i] - k));
        res = min(res, exp);
    }
    cout << res + 1;
    return 0;
}