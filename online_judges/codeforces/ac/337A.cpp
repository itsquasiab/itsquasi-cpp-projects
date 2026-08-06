// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "337A"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

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
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + m);
    ll res = 10000;
    for (int i = 1; i <= m - n + 1; ++i){
        res = min(res, abs(a[i] - a[i + n - 1]));
    }
    cout << res;
    return 0;
}