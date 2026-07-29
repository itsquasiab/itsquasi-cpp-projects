// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "d"

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
        int type;
        cin >> type;
        if (type == 1){
            int k;
            ll x;
            cin >> k >> x;
        }
        else {
            int k;
            cin >> k;
        }
    }
    return 0;
}