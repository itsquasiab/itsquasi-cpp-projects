// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "dsth"

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
    ll a, b, n;
    cin >> a >> b >> n;
    if (n == 1) cout << a;
    else if (n == 2) cout << b;
    else {
        n %= 6;
        if (n == 1) cout << a;
        else if (n == 2) cout << b;
        else if (n == 3) cout << b - a;
        else if (n == 4) cout << -a;
        else if (n == 5) cout << -b;
        else if (n == 0) cout << a - b;
    }
    return 0;
}