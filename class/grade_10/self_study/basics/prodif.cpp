// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "prodif"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll cnt(ll d, ll p){
    ll delta = d * d + 4 * p;
    if (delta < 0) return 0;
    ll s = sqrt(delta);
    if (s * s != delta) return 0;
    ll res = 0;
    if ((-d + s) % 2 == 0) res++;
    if (s != 0 && (-d - s) % 2 == 0) res++;
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
        ll d, p;
        cin >> d >> p;
        cout << cnt(d, p) + (d != 0 ? cnt(-d, p) : 0) << "\n";
    }
    return 0;
}