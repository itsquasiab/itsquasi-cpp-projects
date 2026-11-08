// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "np02"

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
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (q--){
        ll x;
        cin >> x;
        int i = lower_bound(a + 1, a + 1 + n, x) - a;
        if (a[i] != x) cout << 0 << " " << 0 << "\n";
        else{
            int j = upper_bound(a + 1, a + 1 + n, x) - a - 1;
            cout << i << " " << j << "\n";
        }
    }
    return 0;
}