//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1) res *= x;
        x *= x;
        y /= 2;
    }
    return res;
}

ll binsearch(ll n, ll k){
    ll lo = 1, hi = pow(n, 1.0 / k) + 2;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll val = fastpow(mid, k);
        if (val <= n) lo = mid + 1;
        else hi = mid - 1;
    }
    return hi;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        ll l, r;
        cin >> l >> r;
        ll res = 1;
        for (int k = 40; k >= 2; --k){
            long long x_min = binsearch(l - 1, k) + 1;
            long long x_max = binsearch(r, k);
            if (x_min <= x_max) {
                res = k;
                break;
            }
        }
        cout << "Case #" << i << ": " << res << "\n";
    }
    return 0;
}