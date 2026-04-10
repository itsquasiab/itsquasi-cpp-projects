// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bai50"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll pf[arr];

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
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        pf[i] = pf[i - 1] + a;
    }
    int q;
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        cout << pf[v] - pf[u - 1] << "\n";
    }
    return 0;
}