//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    ll w;
    cin >> n >> w;

    pair<ll, ll> a[n + 1];
    ll sumv = 0;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second, sumv += a[i].second;

    vector<ll> dp(sumv + 1, 1e18);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (ll j = sumv; j >= a[i].second; j--)
            dp[j] = min(dp[j], dp[j - a[i].second] + a[i].first);
    }

    ll res = 0;
    for (ll j = 0; j <= sumv; j++)
        if (dp[j] <= w)
            res = j;

    cout << res;
}