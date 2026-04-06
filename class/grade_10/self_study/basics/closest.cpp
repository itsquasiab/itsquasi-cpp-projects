// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "closest"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll fastpow(ll a, ll b){
    if (b == 0) return 1;
    if (b < 0) return 0;
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a;
        }
        a = a * a;
        b /= 2;
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
    int t;
    cin >> t;
    while (t--){
        ll a, b, x;
        cin >> a >> b >> x;
        ll n = fastpow(a, b);
        ll k = n / x * x;
        if (abs(n - k) <= abs(n - (k + x))) cout << k << "\n";
        else cout << k + x << "\n";
    }
    return 0;
}