// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "sotoigian"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll sumdig(ll n){
    ll t = 0;
    while (n){
        t += n % 10;
        n /= 10;
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
    ll n;
    cin >> n;
    cout << sumdig(sumdig(n));
    return 0;
}