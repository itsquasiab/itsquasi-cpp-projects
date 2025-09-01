//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 5e3 + 6, MOD = 1e9 + 9;

ll a[ARR][ARR], pref[ARR][ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    pref[0][0] = 0;
    for (int i = 1; i <= m; ++i) pref[i][0] = 0;
    for (int j = 1; j <= n; ++j) pref[0][j] = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 0; i <= m; ++i){
        for (int j = 0; j <= n; ++j){
            cout << pref[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}