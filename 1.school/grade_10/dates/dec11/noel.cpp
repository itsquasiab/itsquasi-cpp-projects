#include <iostream>
#define ll long long
#define tname "noel"

using namespace std;

const ll arr = 5006, mod = 1e9 + 7;

int n, k;
ll a[arr], b[arr], dp[arr][arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n * k; ++i) cin >> a[i];
    for (int j = 1; j <= n * k; ++j) cin >> b[j];
    for (int i = 1; i <= n * k; ++i){
        for (int j = 1; j <= n * k; ++j){
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n * k][n * k];
    return 0;
}

