// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1635"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= x; ++i){
        dp[i] = 0;
        for (int j = 1; j <= n; ++j){
            if (a[j] <= i) dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }
    cout << dp[x];
    return 0;
}