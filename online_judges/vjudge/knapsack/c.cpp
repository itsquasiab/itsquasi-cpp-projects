// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "c"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll w[arr], v[arr], dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll s;
    cin >> n >> s;
    ll vals = 0;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i], vals += v[i];
    ll res = 0;
    dp[0] = 0;
    for (int i = 1; i <= vals; ++i) dp[i] = 1e18;
    for (int j = 1; j <= n; ++j){
        for (int i = vals; i >= v[j]; --i){
            dp[i] = min(dp[i], dp[i - v[j]] + w[j]);
        }
    }
    for (int i = 1; i <= vals; ++i){
        if (dp[i] <= s) res = i;
    }
    cout << res;
    return 0;
}