#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1006];
ll dp[1006];
bool ok[1006];

ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a + 1, a + 1 + n);
    dp[0] = 1;
    for (int i = 1; i <= 7; ++i){
        for (int j = 1; j <= n && a[j] <= i; ++j){
            dp[i] += dp[i - a[j]];
            cout << dp[i - a[j]] << " ";
        }
        cout << dp[i] << "\n";
    }
    cout << dp[t];
    return 0;
}
