// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "b"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n;
ll check(ll mid){
    ll cnt = 0;
    for (ll i = 1; i <= n; ++i){
        cnt += min(n, mid / i);
    }
    /*ll i = 1;
    while (i <= n){
        ll v = mid / i;
        if (v == 0) break;
        ll imx = mid / v;
        ll r = min(n, imx);
        cnt += (r - i + 1) * min(v, n);
        i = r + 1;
    }*/
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    ll l = 1, r = n * n, res = 0;
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (check(mid) >= (n * n + 1) / 2){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}