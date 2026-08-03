// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "c"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

// C(k, n) = n! / (k! * (n - k)!)
// C(k - 1, n + k - 1) = (n + k - 1)! / ((k - 1)! * (n)!)

ll f[arr];

ll mul(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1){
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

ll c(ll n, ll k){
    return f[n] * mul(f[k], mod - 2) % mod * mul(f[n - k], mod - 2) % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        ll n, k;
        cin >> n >> k;
        ll res = 1;
        if ((n - k) <= (k - 1)) k = n - k + 1;
        for (int i = 1; i < k; ++i) res = res * (n - i) / i;
        /*f[0] = 1;
        for (int i = 1; i <= n; ++i) f[i] = (f[i - 1] * i) % mod;
        cout << c(n, k) << "\n";*/
        cout << res << "\n";
    }
    return 0;
}