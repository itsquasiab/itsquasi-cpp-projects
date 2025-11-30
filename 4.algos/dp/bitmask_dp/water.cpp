//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 22, mod = 1e9 + 7;

int n, k;
ll a[arr][arr];
const ll mx_sz = (1 << 20);
ll dp[mx_sz];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < (1 << n); ++i){
        dp[i] = LLONG_MAX;
    }
    dp[(1 << n) - 1] = 0;
    for (int mask = (1 << n) - 2; mask > 0; --mask){
        for (int i = 0; i < n; ++i){
            if ((mask & (1 << i)) == 0){
                int aftermask = mask | (1 << i);
                for (int j = 0; j < n; ++j){
                    if (mask >> j & 1){
                        dp[mask] = min(dp[mask], dp[aftermask] + a[i][j]);
                    }
                }
            }
        }
    }
    ll res = LLONG_MAX;
    for (int mask = 1; mask < (1 << n); ++mask){
        int t = __builtin_popcount(mask);
        if (t == k) res = min(res, dp[mask]);
    }
    cout << res;
    return 0;
}