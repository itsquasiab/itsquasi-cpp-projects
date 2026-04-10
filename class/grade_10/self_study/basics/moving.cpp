// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#include <iomanip>
#define ll long long
#define task "moving"

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
    ll l, v1, v2;
    cin >> l >> v1 >> v2;
    ll d = abs(v1 - v2);
    int t;
    cin >> t;
    while (t--){
        ll q;
        cin >> q;
        long double f = (sqrt(2) * (l - sqrt(q))) / d;
        cout << fixed << setprecision(6) << f << "\n";
    }
    return 0;
}