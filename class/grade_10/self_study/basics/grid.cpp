// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "grid"

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
    ll r, c;
    cin >> r >> c;
    if (r & 1){
        r = (r - 1) / 2 * 10;
        c = c * 2 - 2;
        cout << r + c;
    }
    else {
        r = (r - 1) / 2 * 10 + 1;
        c = c * 2 - 2;
        cout << r + c;
    }
    return 0;
}