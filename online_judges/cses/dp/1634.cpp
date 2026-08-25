// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1634"

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
    dp[0] = 0;
    for (int i = 1; i <= x; ++i){
        dp[i] = 1e18;
        for (int j = 1; j <= n; ++j){
            if (a[j] <= i){
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
                //cout << dp[i - a[j]] << " ";
            }
        }
        //cout << "|" << i << ": " << dp[i] << "\n";
    }
    if (dp[x] == 1e18) cout << -1;
    else cout << dp[x];
    return 0;
}