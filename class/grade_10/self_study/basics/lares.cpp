// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "lares"

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
    ll m, n, k;
    cin >> m >> n >> k;
    ll total = m + n;
    ll l = 0, r = min(m / 2, n), res = 0;
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (total - 3 * mid >= k){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res;
    return 0;
}