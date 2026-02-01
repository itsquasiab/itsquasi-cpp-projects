//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 106, mod = 1e9, inf = LLONG_MIN;

ll a[arr][arr], dp[arr][arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= m; ++i) dp[i][1] = a[i][1];
    ll mx = inf;
    for (int j = 2; j <= n; ++j){
        for (int i = 1; i <= m; ++i){
            dp[i][j] = dp[i][j-1] + a[i][j];
            if(i > 1) dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + a[i][j]);
            if (i < m) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
           
        }
    }
    for(int i = 1;i <= m; ++i) mx = max(mx , dp[i][n]);
    cout << mx;
    return 0;
}