// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "dance"

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
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort (a + 1, a + 1 + m);
    sort (b + 1, b + 1 + n);
    int i = 1, j = 1;
    ll res = 0;
    while (i <= m && j <= n){
        if (a[i] > b[j]){
            res++;
            i++;
            j++;
        }
        else if (a[i] <= b[j]){
            i++;
        }
    }
    cout << res;
    return 0;
}