//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 4006, mod = 1e9 + 7, inf = LLONG_MIN;

ll f[arr][arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) f[1][i] = 1;
    for (int j = 1; j <= n; ++j){
        for (int i = 2; i <= sqrt(2 * j); ++i){
            f[i][j] = (f[i - 1][j - i] + f[i][j - i]) % mod;
        }
    }
    ll res = 0;
    for (int i = 2; i <= sqrt(2 * n); ++i){
        res = (res + f[i][n]) % mod;
    }
    cout << res;
    return 0;
}