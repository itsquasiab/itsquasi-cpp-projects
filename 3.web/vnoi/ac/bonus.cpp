// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <climits>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

int n, k;

ll a[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    ll res = LLONG_MIN;
    for (int i = k; i <= n; ++i){
        for (int j = k; j <= n; ++j){
            res = max(res, a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k]);
        }
    }
    cout << res;
    return 0;
}