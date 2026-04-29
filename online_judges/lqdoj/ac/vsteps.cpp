// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "vsteps"

using namespace std;

const ll arr = 1e5 + 6, mod = 14062008;

bool broken[arr];
ll dp[arr];

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
    for (int i = 1; i <= k; ++i){
        int j;
        cin >> j;
        broken[j] = 1;
    }
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i <= n; ++i){
        if (broken[i]){
            dp[i] = 0;
        }
        else{
            dp[i] = (dp[i - 1] + dp[i - 2]);
        }
        dp[i] %= mod;
    }
    cout << dp[n] % mod;
    return 0;
}