// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;
ll a[arr];
bool n_is_even;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    if (n % 2 == 0) n_is_even = 1;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    ll c1, c2, res1, res2;
    c1 = a[(n + 1) / 2], res1 = 0;
    if (n_is_even) c2 = a[n / 2 + 1],  res2 = 0;
    for (int i = 1; i <= n; ++i){
        res1 += abs(c1 - a[i]);
        if (n_is_even) res2 += abs(c2 - a[i]);
    }
    cout << (n_is_even ? min(res1, res2) : res1);
    return 0;
}