// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define task "sodu"

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;
ll a[arr];
ll res = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            res = max(res, a[j] % a[i]);
        }
    }
    cout << res;
    return 0;
}