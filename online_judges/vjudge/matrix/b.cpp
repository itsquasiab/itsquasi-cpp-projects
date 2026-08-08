// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "b"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

char a[arr][arr];
ll dp[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j){
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }
    ll mx = 1;
    for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j){
            if (i == 1 && j == 1 && a[i][j] == '.') dp[i][j] = 1;
            if (a[i][j] == '#') continue;
            
            if (i > 1 && dp[i - 1][j] != -1){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j > 1 && dp[i][j - 1] != -1){
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            }
            mx = max(mx, dp[i][j]);
        }
    }
    /*for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << mx;
    return 0;
}