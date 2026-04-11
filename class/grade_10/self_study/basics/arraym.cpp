// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "arraym"

using namespace std;

const ll arr = 1e7 + 6, mod = 1e9 + 7;

ll pf[arr];

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
    for (int i = 1; i <= m; ++i){
        int u, v;
        ll k;
        cin >> u >> v >> k;
        pf[u] += k;
        pf[v + 1] -= k;
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        pf[i] += pf[i - 1];
        res = max(res, pf[i]);
        //cout << pf[i] << " ";
    }
    cout << res;
    return 0;
}