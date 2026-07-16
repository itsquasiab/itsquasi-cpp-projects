// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cau1a"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;

ll tll (ll n){
    ll t = 0;
    for (int i = 1; i <= n; ++i){
        t += n / 2;
        n /= 2;
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
    cin >> n;
    cout << n - 1 << "\n" << tll(n);
    return 0;
}