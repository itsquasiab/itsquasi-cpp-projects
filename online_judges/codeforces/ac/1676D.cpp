//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int m, n;
        cin >> m >> n;
        ll a[m + 5][n + 5], dag[m + n + 5], cdag[m + n + 5];
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= m + n; ++i){
            dag[i] = 0;
            cdag[i] = 0;
        }
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                int i1 = i - j + n;
                int i2 = i + j;
                dag[i1] += a[i][j];
                cdag[i2] += a[i][j];
            }
        }
        ll res = 0;
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                int i1 = i - j + n;
                int i2 = i + j;
                res = max(res, dag[i1] + cdag[i2] - a[i][j]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}