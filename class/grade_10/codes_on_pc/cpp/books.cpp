#include<bits/stdc++.h>
#define ll long long

using namespace std;

pair<ll,ll> a[1006];
ll dp[1006][1006];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i].first;
    for (int i = 1; i <= n; ++i) cin >> a[i].second;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= t; ++j){
            if (j >= a[i].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].first] + a[i].second);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][t];
    return 0;
}

