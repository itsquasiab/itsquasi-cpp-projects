// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#define ll long long
#define task "caythong"

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

ll a[arr], b[arr];
ll res = LLONG_MAX;

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
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i){
        int j = lower_bound(b + 1, b + 1 + n, a[i] * -1) - b;
        res = min(res, abs(a[i] + b[j]));
        if (j > 1) res = min(res, abs(a[i] + b[j - 1]));
    }
    cout << res;
    return 0;
}