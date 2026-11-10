// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "ds12"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll a[arr], b[arr], c[arr], d[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> c[i];
    for (int i = 1; i <= m; ++i) cin >> b[i] >> d[i];
    return 0;
}