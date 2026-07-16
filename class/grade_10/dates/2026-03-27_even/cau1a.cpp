// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cau1a"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a, b;

ll rev(ll a){
    ll t = 0;
    while (a){
        t = t * 10 + (a % 10);
        a /= 10;
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> a >> b;
    cout << max(rev(a), rev(b));
    return 0;
}