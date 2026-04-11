// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "special"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr][arr], mn[arr], mx[arr];

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
    for (int i = 2; i <= n + n; ++i){
        mn[i] = 1e18;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            mx[i - j + n] = max(mx[i - j + n], a[i][j]);
            mn[i + j] = min(mn[i + j], a[i][j]);
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (a[i][j] == mx[i - j + n] && a[i][j] == mn[i + j]) res += a[i][j];
        }
    }
    cout << res;
    return 0;
}