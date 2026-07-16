// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr], f[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int n, k;
    cin >> n >> k;
    int j = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i){
        f[i] = f[i - 1];
        while (a[j + 1] <= a[i] - k) j++;
        f[i] = max(f[i - 1], f[j] + b[i]);
    }
    cout << f[n];
    return 0;
}