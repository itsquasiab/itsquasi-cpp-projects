// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "gex"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int q;
    cin >> q;
    while (q--){
        ll n;
        cin >> n;
        ll x = sqrt(n);
        if (x * x < n) cout << x + 1 << "\n";
        else cout << x << "\n";
    }
    return 0;
}