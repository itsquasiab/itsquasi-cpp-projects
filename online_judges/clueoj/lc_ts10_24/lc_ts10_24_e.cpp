// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "lc_ts10_24_e"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
unordered_map<ll, int> pos;

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
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (!pos.count(a[i])) pos[a[i]] = i;
        else {
            res = max(res, a[i] + a[i - 1] - a[pos[a[i]] - 1]);
        }
        a[i] += a[i - 1];
    }
    cout << res;
    return 0;
}