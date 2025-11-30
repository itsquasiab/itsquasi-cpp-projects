#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
pair<ll, ll> a[arr];
ll dp[arr];
ll ed[arr];

bool sorter(pair<ll,ll> a, pair<ll,ll> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort (a + 1, a + 1 + n, sorter);
    for (int i = 1; i <= n; ++i){
        ed[i] = a[i].second;
    }
    for (int i = 1; i <= n; ++i){
        ll w = a[i].second - a[i].first;
        int j = lower_bound(ed + 1, ed + 1 + n, a[i].first - 1) - ed;
        ll best = (j >= 0 ? dp[j] : 0);
        ll take = best + w;
        ll skip = (i > 0 ? dp[i - 1] : 0);
        dp[i] = max(take, skip);
    }
    cout << dp[n];
    return 0;
}
