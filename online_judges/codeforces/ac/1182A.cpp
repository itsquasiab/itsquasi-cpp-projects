// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "1182A"

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
    int n;
    cin >> n;
    if (n & 1) cout << 0;
    else { 
        ll res = pow(2, n / 2);
        cout << res;
    }
    return 0;
}