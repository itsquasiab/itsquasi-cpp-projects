//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 3006, mod = 1e9, inf = LLONG_MIN;

ll dp[arr][arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string x, y;
    cin >> x >> y;
    int m = x.size(), n = y.size();
    x = " " + x;
    y = " " + y;
    string str;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (x[i] == y[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    while (m > 0 && n > 0){
        if (x[m] == y[n]) str = x[m] + str, --m, --n;
        else if (dp[m - 1][n] > dp[m][n - 1]) --m;
        else --n;
    }
    cout << str;
    return 0;
}