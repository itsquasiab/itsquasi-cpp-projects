// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <iomanip>
#define ll long long
#define task "cdl1p3"

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
    long double x;
    cin >> x;
    cout << fixed << setprecision(2) << x * 2.205;
    return 0;
}