//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a[arr], dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= n; ++j){
        for (int i = a[j]; i <= x; ++i){
            dp[i] += dp[i - a[j]];
            dp[i] %= mod;
        }
    }
    cout << dp[x];
    return 0;
}