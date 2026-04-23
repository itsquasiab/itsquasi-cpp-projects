// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "nkcable"

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
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for (int i = 3; i < n; ++i){
        dp[i] = min(dp[i - 1], dp[i - 2]) + a[i];
    }
    cout << dp[n - 1];
    return 0;
}