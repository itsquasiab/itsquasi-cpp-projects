#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[8][arr];
ll dp[8][arr];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= 3; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    dp[2][1] = a[2][1];
    dp[3][1] = a[3][1];
    for (int j = 2; j <= n; ++j){
        dp[1][j] = max({dp[1][j - 1], dp[2][j - 1]}) + a[1][j];
        dp[2][j] = max({dp[1][j - 1], dp[2][j - 1], dp[3][j - 1]}) + a[2][j];
        dp[3][j] = max({dp[2][j - 1], dp[3][j - 1]}) + a[3][j];
    }
    cout << max({dp[1][n], dp[2][n], dp[3][n]});
    return 0;
}

