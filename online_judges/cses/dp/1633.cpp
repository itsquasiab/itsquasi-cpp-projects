// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1633"

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
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= 6; ++j){
            if (i >= j) dp[i] = (dp[i] + dp[i - j]) % mod;
        }
        //cout << dp[i] << "\n";
    }
    cout << dp[n];
    return 0;
}