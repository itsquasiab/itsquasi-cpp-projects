#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 24, mod = 1e9 + 7;

int n, k;
ll a[arr][arr];
const ll maximum_size = (1 << 20);
ll dp[maximum_size];

int main(){
    if (fopen("water.inp","r")){
        freopen("water.inp","r",stdin);
        freopen("water.out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask){
        dp[mask] = LLONG_MAX;
    }
    dp[(1 << n) - 1] = 0;
    for (int mask = (1 << n) - 2; mask > 0; --mask){
        for (int i = 0; i < n; ++i){
            if ((mask & (1 << i)) == 0){
                int aftermask = mask | (1 << i);
                for (int j = 0; j < n; ++j){
                if (mask >> j & 1)
                dp[mask] = min(dp[mask], dp[aftermask] + a[i][j]);
                }
            }
        }
    }
    ll res = LLONG_MAX;
    for (int mask = 1; mask < (1 << n); ++mask){
        ll t = __builtin_popcount(mask);
        if (t == k) res = min(res, dp[mask]);
    }
    cout << res;
    return 0;
}

