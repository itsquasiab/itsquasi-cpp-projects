// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "hn_hsg9_22_a"

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
    ll s1, v1, s2, v2;
    cin >> s1 >> v1 >> s2 >> v2;
    // s1 + v1 * x = s2 + v2 * x
    // (v1 - v2) * x = s2 - s1
    ll ac = v1 - v2;
    ll db = s2 - s1;
    // ac * x = db
    if (s1 != s2 && ac != 0 && (db / ac) >= 0) cout << (db / ac);
    else cout << -1;
    return 0;
}