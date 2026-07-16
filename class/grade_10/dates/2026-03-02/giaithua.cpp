// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "giaithua"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll t = 1, s = 1;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll a;
    cin >> a;
    for (ll i = 2; i <= a; ++i){
        t = (t * i) % mod;
        s = (s + t) % mod;
    }
    cout << s;
    return 0;
}