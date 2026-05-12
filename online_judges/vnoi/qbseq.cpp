// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "qbseq"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr];
ll dp[arr][56];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] %= k;
    }
    for (int j = 2; j <= n; ++j){
        dp[1][j] = -1e18;
    }
    dp[1][a[1]] = 1;
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i){
        for (int j = 0; j < k; ++j){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] + k) % k] + 1);
        }
    }
    cout << dp[n][0];
    return 0;
}