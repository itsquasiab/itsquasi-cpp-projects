//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, inf = LLONG_MIN;

ll a[arr], dp[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= t; ++i){
        for (int j = 1; j <= n; ++j){
            if (i - a[j] >= 0){
            dp[i] += dp[i - a[j]];
            dp[i] %= mod;
            }
        }
    }
    cout << dp[t] % mod;
    return 0;
}