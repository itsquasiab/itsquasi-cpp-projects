#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1000006], dp[1000006];
bool exist[1000006];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[0] = 0;
    exist[0] = 1;
    for (int i = 1; i <= t; ++i){
        dp[i] = INT_MAX;
        exist[i] = 0;
        for (int j = 1; j <= n; ++j){
            if (i - a[j] >= 0 && exist[i - a[j]] == 1) dp[i] = min(dp[i], dp[i - a[j]] + 1), exist[i] = 1;
            //cout << dp[i] << " ";
        }
        //cout << dp[i] << "\n";
    }
    cout << (exist[t] ? dp[t] : 0);
    return 0;
}
