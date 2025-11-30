//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 20, mod = 1e9 + 7;

int n;
ll m;
pair<ll, ll> a[arr];
ll dp[(1 << arr)];
ll wg[(1 << arr)];
ll cn[(1 << arr)];

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    dp[0] = 0;
    wg[0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask){
        for (int i = 0; i < n; ++i){
            if ((mask & (1 << i)) == 0 && wg[mask] + a[i].first <= m){
                int new_mask = mask | (1 << i);
                if (dp[new_mask] < dp[mask] + a[i].second){
                    dp[new_mask] = dp[mask] + a[i].second;
                    wg[new_mask] = wg[mask] + a[i].first;
                }
                else if (dp[new_mask] == dp[mask] + a[i].second){
                    wg[new_mask] = min(wg[new_mask], wg[mask] + a[i].first);
                }
            }
        }
    }
    ll highest = 0;
    ll res = 0;
    for (int mask = 0; mask < (1 << n); ++mask){
        if (dp[mask] > highest){
            highest = dp[mask];
            res = mask;
        }
    }
    cout << __builtin_popcount(res) << "\n";
    int pos = 1;
    while(res){
        int t = res % 2;
        res /= 2;
        if (t == 1) cout << pos << " ";
        pos++;
    }
    return 0;
}