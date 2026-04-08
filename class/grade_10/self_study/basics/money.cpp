// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "money"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll b;
    cin >> n >> b;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll last_min = a[1];
    ll res = b;
    for (int i = 2; i <= n; ++i){
        res = max(res, (b / last_min * a[i]) + (b % last_min));
        last_min = min(last_min, a[i]);
    }
    cout << res;
    return 0;
}