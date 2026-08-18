// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "a"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= x; ++i){
        //cout << i << "|\n";
        for (int j = 1; j <= n; ++j){
            if (i - a[j] >= 0){
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
                //cout << i - a[j] << "\n";
            }
        }
    }
    cout << dp[x] % mod;
    return 0;
}