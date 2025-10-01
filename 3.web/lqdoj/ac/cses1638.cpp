//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1006, mod = 1e9 + 7, inf = LLONG_MIN;

char a[arr][arr];
ll dp[arr][arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }

    if (a[1][1] == '*' || a[n][n] == '*'){
        cout << 0;
        return 0;
    }
    
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i){
        if (a[1][i] == '*') break;
        dp[1][i] = 1;
    }

    for (int i = 1; i <= n; ++i){
        if (a[i][1] == '*') break;
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; ++i){
        for (int j = 2; j <= n; ++j){
            if (a[i][j] == '*') continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][n] % mod;
    return 0;
}