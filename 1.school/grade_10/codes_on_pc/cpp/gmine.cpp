#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 3006, mod = 1e9 + 7;

pair<ll, ll> a[arr];
ll dp[arr][arr];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    return 0;
}
