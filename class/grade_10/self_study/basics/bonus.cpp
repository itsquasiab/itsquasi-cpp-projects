// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bonus"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll pf[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            ll a;
            cin >> a;
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + a;
        }
    }
    ll mx = 0;
    for (int i = k; i <= n; ++i){
        for (int j = k; j <= n; ++j){
            mx = max(mx, pf[i][j] - pf[i - k][j] - pf[i][j - k] + pf[i - k][j - k]);
        }
    }
    cout << mx;
    return 0;
}