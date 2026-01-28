// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    while (cin >> n){
        if (n == 0) break;
        ll res = n * (n + 1) * (2 * n + 1) / 6;
        cout << res << "\n";
    }
    return 0;
}