//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

int m, n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;

    int a[m + 5][n + 5];
    ll dp0[m + 5][n + 5];
    ll dp1[m + 5][n + 5];

    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));

    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    ll mx = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (a[i][j] == 0){
                if (i == 1 && j == 1) dp0[1][1] = 1;
                else dp0[i][j] = min({dp0[i - 1][j], dp0[i][j - 1], dp0[i - 1][j - 1]}) + 1;
            }
            else if (a[i][j] == 1){
                if (i == 1 && j == 1) dp1[1][1] = 1;
                else dp1[i][j] = min({dp1[i - 1][j], dp1[i][j - 1], dp1[i - 1][j - 1]}) + 1;
            }
            mx = max({mx, dp0[i][j], dp1[i][j]});
        }
    }
    cout << mx;
    return 0;
}