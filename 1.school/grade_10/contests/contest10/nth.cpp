//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
ll a[arr];
ll dp[1004][1004];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("nth.inp","r"))
    {
        freopen("nth.inp", "r", stdin);
        freopen("nth.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    a[0] = 0;
    a[n + 1] = m;
    for (int i = 0; i <= n + 2; ++i){
        for (int j = 0; j <= n + 2; ++j){
            dp[i][j] = 0;
        }
    }
    for (int len = 2; len <= n + 1; ++len) {
        for (int i = 0; i + len <= n + 1; ++i) {
            int j = i + len;
            dp[i][j] = LLONG_MAX;

            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j],
                               dp[i][k] + dp[k][j] + (a[j] - a[i]));
            }
        }
    }
    cout << dp[0][n + 1];
    return 0;
}