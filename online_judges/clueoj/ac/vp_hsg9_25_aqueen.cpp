// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "hn_hsg9_22_d"

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
    ll m, n;
    cin >> m >> n;
    ll heigth = m - 1;
    ll width = n - 1;
    ll r = m / 2, c = n / 2;
    ll diag = min(r, c)
            + min(r, n - 1 - c)
            + min(m - 1 - r, c)
            + min(m - 1 - r, n - 1- c);
    //cout << diag << "\n";
    cout << heigth + width + diag;
    return 0;
}
