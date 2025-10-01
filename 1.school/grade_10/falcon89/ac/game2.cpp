//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[4][arr], dp[4][arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 3; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    dp[2][1] = a[2][1];
    dp[3][1] = a[3][1];
    for (int i = 2; i <= n; ++i){
        dp[1][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[1][i];
        dp[2][i] = max({dp[1][i - 1], dp[2][i - 1], dp[3][i - 1]}) + a[2][i];
        dp[3][i] = max(dp[2][i - 1], dp[3][i - 1]) + a[3][i];
    }
    cout << max({dp[1][n], dp[2][n], dp[3][n]});
    return 0;
}