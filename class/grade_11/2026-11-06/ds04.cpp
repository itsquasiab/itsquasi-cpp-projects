// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "ds04"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll dp[arr];

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
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        int j = lower_bound(dp + 1, dp + res + 1, a) - dp;
        dp[j] = a;
        res = max(res, j * 1ll);
    }
    cout << res;
    return 0;
}