// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n, d;
ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> d;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    ll len = 0;
    int r = 1;
    for (int i = 1; i <= n - 2; ++i){
        while (r <= n && a[r] - a[i] <= d) {
            ++r;
        }
        ll cnt = r - i - 1;

        if (cnt >= 2) {
            len += cnt * (cnt - 1) / 2;
        }
    }
    cout << len;
    return 0;
}