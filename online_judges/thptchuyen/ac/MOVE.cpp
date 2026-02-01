//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 506, mod = 1e9 + 7;

int n, m;
ll a[arr][arr];
ll dp[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i){
        dp[i][1] = dp[i - 1][1] + a[i][1];
    }
    for (int i = 1; i <= m; ++i){
        dp[1][i] = dp[1][i - 1] + a[1][i];
    }
    for (int i = 2; i <= n; ++i){
        for (int j = 2; j <= m; ++j){
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    /*for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[n][m];
    return 0;
}