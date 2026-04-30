// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <numeric>
#define ll long long
#define task "gcd_debugging"

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
    int a = 12, b = -18;
    cout << "__gcd(" << a << ", " << b << ") = " << __gcd(a, b) << "\n";
    cout << "std::gcd(" << a << ", " << b << ") = " << gcd(a, b) << "\n";
    return 0;
}