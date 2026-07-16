// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "captoc"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

ll a[arr][arr], dp[arr][arr];

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
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= x; ++j){
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= x; ++j){
        dp[1][j] = a[1][j];
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= x; ++j){
            dp[i][j] = 0;
            for (int k = 0; k <= j; ++k){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[i][k]);
            }
        }
    }
    cout << dp[n][x];
    return 0;
}