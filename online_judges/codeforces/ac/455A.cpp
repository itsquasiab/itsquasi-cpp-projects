// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "455A"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], dp[arr];
unordered_map<ll, ll> cnt;

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
    ll mx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }
    dp[0] = 0;
    dp[1] = 1 * cnt[1];
    ll res = dp[1];
    for (int i = 2; i <= mx; ++i){
        dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}