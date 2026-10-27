// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <numeric>
#define ll long long
#define task "cau1"

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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll us = b * y / gcd(b, y);
    a = us / b * a;
    x = us / y * x;
    ll ts = a + x;
    cout << ts / gcd(ts, us) << " " << us / gcd(ts, us);
    return 0;
}