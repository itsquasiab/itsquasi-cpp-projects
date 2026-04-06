//not done yet, i'm just gonna send it to my laptop and continue with this
#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr1 = 22, arr2 = 1e6 + 6;

int n;
ll a[arr1], b[arr1][arr1];
ll dp[arr2][arr1];

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    ll original_sum = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], original_sum += a[i];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int mask = 1; mask < (1 << n); ++mask){
            dp[mask][i] = LLONG_MIN;
        }
    }
    for (int i = 1; i <= n; ++i){
    for (int mask = 0; mask < (1 << n); ++mask){
            // another for loop when needed
            for (int p = 1; p <= n; ++p){
                if (!(mask & (1 << p))) {
                    int new_mask = mask | (1 << p);
                    dp[new_mask][i] = max(dp[new_mask][i], dp[mask][i] + (a[p] - b[i][p]));
                    //cout << dp[new_mask][i] << "\n";
                }
            }
        }
    }
    ll t = 0;
    ll power = pow(2, n) - 1;
    for (int i = 1; i <= n; ++i){
        t = max(t, dp[power][i]);
    }
    cout << original_sum - t;
    return 0;
}
/*
3
8 4 5
0 1 1
3 0 1
2 4 0
*/
