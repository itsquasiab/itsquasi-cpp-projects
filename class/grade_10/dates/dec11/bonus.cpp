#include <iostream>
#define ll long long
#define tname "bonus"

using namespace std;

const ll arr = 2006, mod = 1e9 + 7;

int n, d;
ll a[arr], dp[arr][arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> d;
    for (int i = 1; i <= n * 2; ++i) cin >> a[i];
    for (int i = 1; i <= n * 2; ++i){
        for (int j = 1; j <= n * 2; ++j){
            if (abs(a[i] - a[j]) <= d) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n * 2][n * 2];
    return 0;
}


