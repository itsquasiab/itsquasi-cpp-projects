#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[10006], dp[10006];

ll cnt[10006][10006];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= t; ++i){
        dp[i] = INT_MAX;
        for (int j = 1; j <= n; ++j){
            if (i - a[j] >= 0 && dp[i] < dp[i - a[j]] + 1){
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
                cnt[i][j]++;
            }
        }
    }
    cout << dp[t] << "\n";
    for (int i = 1; i <= n; ++i){
        cout << cnt[t][i] << " ";
    }
    return 0;
}
