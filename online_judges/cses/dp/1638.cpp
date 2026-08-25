// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1638"
 
using namespace std;
 
const ll arr = 1006, mod = 1e9 + 7;
 
ll a[arr][arr], dp[arr][arr];
 
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
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            char c;
            cin >> c;
            if (c == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (i == 1 && j == 1){
                if (a[i][j] == 0) continue;
                else dp[1][1] = 0;
            }
            if (a[i][j]) continue;
            else dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j] + dp[i][j - 1]) % mod;
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << dp[n][n];
    return 0;
}