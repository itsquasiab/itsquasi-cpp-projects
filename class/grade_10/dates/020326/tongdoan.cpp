// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "tongdoan"

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
    ll a, b;
    cin >> a >> b;
    //ll f1 = a * (a - 1) / 2;
    //ll f2 = b * (b + 1) / 2;
    ll f3 = (a + b) * (b - a + 1) / 2;
    cout << f3;
    return 0;
}