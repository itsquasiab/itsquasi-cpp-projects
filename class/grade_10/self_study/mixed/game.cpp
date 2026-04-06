#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
ll dp[arr], cnt[arr];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[1] = a[1], cnt[1] = 1;
    dp[2] = a[1] + a[2], cnt[2] = 2;
    for (int i = 3; i <= n; ++i){
        dp[i] = max({dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i] + a[i - 1]});
        //cout << dp[i] << " ";
    }
    cout << dp[n];
    return 0;
}
