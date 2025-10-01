//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e3 + 6, mod = 1e9 + 7, inf = LLONG_MIN;

char a[arr][arr];
ll dp[arr][arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j){
            cin >> a[i][j];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= h; ++i){
        for (int j = 1; j <= w; ++j){
            if (a[i][j] == '#' || (i == 1 && j == 1)) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << dp[h][w];
    return 0;
}