//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, inf = LLONG_MIN;

ll dp[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= 6 && j <= i; ++j){
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] % mod;
    return 0;
}