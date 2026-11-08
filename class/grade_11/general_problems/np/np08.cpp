// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "np08"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

ll check(ll x, int n){
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        res += (x / a[i]);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll l = 0, r = 1e9;
    ll res = 0;
    while (l <= r){
        ll mid = l + ((r - l) >> 1);
        if (check(mid, n) >= k){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}