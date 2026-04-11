// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "stock"

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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        ll res = 0, mx = 0;
        for (int i = n; i >= 1; --i){
            if (a[i] > mx) mx = a[i];
            else res += mx - a[i];
        }
        cout << res << "\n";
    }
    return 0;
}