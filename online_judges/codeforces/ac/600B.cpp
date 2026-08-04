// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "600B"

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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; ++i){
        int j = upper_bound(a + 1, a + 1 + n, b[i]) - a;
        //cout << a[j] << " | " << b[i] << " <> ";
        if (j > n) j = n;
        if (a[j] > b[i]) j--;
        //cout << a[j] << " | " << b[i] << "\n";
        cout << j << "\n";
    }
    return 0;
}