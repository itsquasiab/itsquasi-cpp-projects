// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1636"

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
    for (int i = 1; i <= n; ++i){
        for (int j = a[i]; j <= x; ++j){
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }
    //for (int i = 1; i <= x; ++i) cout << i << ": " << dp[i] << "\n";
    cout << dp[x];
    return 0;
}