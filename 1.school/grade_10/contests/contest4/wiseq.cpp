//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], dp[ARR], sum[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    ll w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll mx = 0;
    for (int i = 1; i <= n; ++i){
        dp[i] = 1;
        sum[i] = a[i];
        for (int j = 1; j < i; ++j){
            //cout << sum[j] + sum[i] << " ";
            if (a[j] < a[i] && sum[j] + a[i] <= w){
                if (dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    sum[i] = a[i] + sum[j];
                }
                else if (dp[i] == dp[j] + 1){
                    sum[i] = min(sum[i], a[i] + sum[j]);
                }
            }
        }
        //cout << dp[i] << "\n";
        mx = max(mx, dp[i]);
    }
    cout << mx;
    return 0;
}