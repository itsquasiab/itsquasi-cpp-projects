// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "rotation"

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
    int n, k, q;
    cin >> n >> k >> q;
    k %= n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    while (q--){
        int m;
        cin >> m;
        int idx = (m - k) % n;
        if (idx < 0) idx += n;
        cout << a[idx] << "\n";
    }
    return 0;
}