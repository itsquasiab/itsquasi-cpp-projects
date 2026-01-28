// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n;
ll dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    if (n == 0) return 0;
    if (n == 1){
        cout << 1;
        return 0;
    }
    if (n == 2){
        cout << 1 << " " << 1;
        return 0;
    }
    dp[0] = dp[1] = 1;
    cout << dp[0] << " " << dp[1] << " ";
    for (int i = 2; i < n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
        cout << dp[i] << " ";
    }
    return 0;
}