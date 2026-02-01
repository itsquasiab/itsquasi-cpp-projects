//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1006, mod = 1e9 + 7, base = 31, arr2 = 1e5 + 6;

pair<ll,ll> a[arr];
ll dp[arr2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i].first;
    for (int i = 1; i <= n; ++i) cin >> a[i].second;
    for (int i = 1; i <= n; ++i){
        for (int j = x; j >= a[i].first; --j){
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }
    ll res = 0;
    for (int i = x; i >= 0; --i){
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}