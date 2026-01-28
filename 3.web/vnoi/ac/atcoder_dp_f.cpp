//2025 = 45² = (20+25)² = 5²*9² = (1+2+3+4+5+6+7+8+9)² = 1³+2³+3³+4³+5³+6³+7³+8³+9³
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[3005][3005];

int main()
{
    /*if (fopen(".inp","r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }*/
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string x,y;
    cin >> x >> y;
    ll m = x.size(), n = y.size();
    x = " " + x;
    y = " " + y;
    string str = "";
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
