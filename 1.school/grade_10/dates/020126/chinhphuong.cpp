// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define task "chinhphuong"

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll l, r;
    cin >> l >> r;
    ll lmn = sqrt(l), rmx = sqrt(r);
    if (lmn * lmn < l) lmn++;
    //cout << rmx << " " << lmn << "\n";
    cout << rmx - lmn + 1;
    return 0;
}