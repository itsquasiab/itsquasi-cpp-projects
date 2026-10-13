// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "QBSTR"

using namespace std;

const ll arr = 1e3 + 6, mod = 1e9 + 7;

ll dp[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m];
    return 0;
}