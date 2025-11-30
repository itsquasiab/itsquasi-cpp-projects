#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e4 + 6, mod = 1e9 + 7;

ll n, k;
ll a[arr], b[arr];
ll dp[arr][arr];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n * k; ++i) cin >> a[i];
    for (int i = 1; i <= n * k; ++i) cin >> b[i];
    for (int i = 1; i <= n * k; ++i){
        for (int j = 1; j <= n * k; ++j){
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n * k][n * k];
    return 0;
}
