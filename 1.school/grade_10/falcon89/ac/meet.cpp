//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a[arr], b[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort (a + 1, a + 1 + n);
    while (k--){
        int x, y;
        cin >> x >> y;
        ll val = (b[x] + b[y]) / 2;
        int pos = lower_bound(a + 1, a + 1 + n, val) - a;

        ll res = max(abs(a[pos] - b[x]), abs(a[pos] - b[y]));

        if (pos > 1) {
            ll alt = max(abs(a[pos - 1] - b[x]), abs(a[pos - 1] - b[y]));
            res = min(res, alt);
        }

        cout << res << "\n";
    }
    return 0;
}