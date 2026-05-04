// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "grid1"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

string ch[arr];

ll dp[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> ch[i];
        ch[i] = ' ' + ch[i];
    }
    dp[1][1] = 1;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i){
        dp[i][0] = 0;
    }
    for (int j = 1; j <= m; ++j){
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (i == 1 && j == 1) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            if (ch[i][j] == '#') dp[i][j] = 0;
        }
    }
    cout << dp[n][m];
    return 0;
}
