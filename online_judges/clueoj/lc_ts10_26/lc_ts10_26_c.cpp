// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "lc_ts10_26_c"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1){
            res *= x;
        }
        x *= x;
        y /= 2;
    }
    return res;
}

ll get_sum_divs(ll n){
    if (n == 1) return 1;
    ll res = 1;
    for (ll i = 2; i * i <= n; ++i){
        if (n % i == 0){
            int e = 0;
            while (n % i == 0){
                n /= i;
                e++;
            }
            res *= (fastpow(i, e + 1) - 1) / (i - 1);
        }
    }
    if (n > 1) res *= (n + 1);
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
    ll n;
    cin >> n;
    ll res = get_sum_divs(n);
    cout << (res & 1 ? "S" : "M") << res;
    return 0;
}