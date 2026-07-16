//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], dp[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int mx = 0;
    /*for (int i = 1; i <= n; ++i){
        dp[i] = 1;
        for (int j = 1; j < i; ++j){
            if (a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }*/
    for (int i = 1; i <= n; ++i){
        int j = lower_bound(dp + 1, dp + mx + 1, a[i]) - dp;
        dp[j] = a[i];
        mx = max(mx, j); 
    }
    cout << mx;
    return 0;
}