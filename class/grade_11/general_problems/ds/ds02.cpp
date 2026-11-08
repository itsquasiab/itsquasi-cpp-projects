// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "ds02"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll m, n, k;

ll counter(ll mid){
    ll cnt = 0;
    for (ll i = 1; i <= m; ++i){
        if (i * i >= mid) break;
        ll calc = sqrt(mid - i * i);
        cnt += min(n, calc);
    }
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
    cin >> m >> n >> k;
    if (m > n) swap(m, n);
    ll l = 2, r = m * m + n * n, res = 2;
    while (l <= r){
        ll mid = l + ((r - l) >> 1);
        //cout << mid << " " << counter(mid) << " ";
        if (counter(mid) >= k){
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        //cout << res << "\n";
    }
    cout << res;
    return 0;
}