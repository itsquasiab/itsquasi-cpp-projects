// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "triplets"

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
    ll a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    ll r1 = 0, r2 = 0;
    if (a > x) r1++;
    else if (a < x) r2++;
    if (b > y) r1++;
    else if (b < y) r2++;
    if (c > z) r1++;
    else if (c < z) r2++;
    cout << r1 << " " << r2;
    return 0;
}