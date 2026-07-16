// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "ABA12C"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

ll a[arr], dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int ts;
    cin >> ts;
    for (int c = 1; c <= ts; ++c){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; ++i){
            cin >> a[i];
            dp[i] = 1e18;
        }
        dp[0] = 0;
        for (int i = 1; i <= k; ++i){
            for (int j = 1; j <= i; ++j){
                if (a[j] != -1 && dp[i - j] != 1e18) dp[i] = min(dp[i], dp[i - j] + a[j]);
            }
        }
        if (dp[k] != 1e18) cout << dp[k] << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}