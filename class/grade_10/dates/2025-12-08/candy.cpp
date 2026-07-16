#include <iostream>
#define ll long long
#define tname "candy"

using namespace std;

const ll arr = 1e5 + 6, mod = 1000000007;

int n, k;
ll dp[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> k;
    int mxlimit = n - (k + 1) * k / 2;
    dp[0] = 1;
    for (int i = 1; i <= k; ++i){
        for (int j = i; j <= mxlimit; ++j){
            if (j - i >= 0) dp[j] = (dp[j - i] + dp[j]) % mod;
        }
    }
    cout << dp[mxlimit];
}
