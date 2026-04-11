// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bonus2"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

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
    ll pf[n + 5][m + 5];
    for (int i = 0; i <= n; ++i) pf[i][0] = 0;
    for (int j = 0; j <= m; ++j) pf[0][j] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            ll a;
            cin >> a;
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + a;
        }
    }
    while (k--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << pf[u][v] - pf[x - 1][v] - pf[u][y - 1] + pf[x - 1][y - 1] << "\n";
    }
    return 0;
}