// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "ANARC08E"

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
    while (1){
        ll a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        cout << a << "+" << b << ((a == 1 || b == 1) ? "=" : "!=") << a + b << "\n";
    }
    return 0;
}