// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define task "captoc"

using namespace std;

const ll arr = 106, mod = 1'000'000'007;

int n, x;
ll a[arr][arr];
ll res = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    if (x == 1){
        for (int j = 1; j <= n; ++j){
            res = max(res, a[1][j]);
        }
    }
    cout << res;
    return 0;
}