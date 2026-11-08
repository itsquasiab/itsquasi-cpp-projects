// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "ds09"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int m, n;
    ll k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort (a + 1, a + 1 + m);
    sort (b + 1, b + 1 + n);
    int i = 1, j = 1, res = 0;
    while (i <= m && j <= n){
        if (abs(a[i] - b[i]) <= k){
            res++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    cout << res << "\n";
    return 0;
}