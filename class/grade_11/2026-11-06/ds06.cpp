// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "ds06"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
int m, n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (m--){
        ll b;
        cin >> b;
        int i = lower_bound(a + 1, a + 1 + n, b) - a;
        cout << i - 1 << " ";
    }
    return 0;
}