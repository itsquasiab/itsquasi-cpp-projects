// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bcpnn"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

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
    ll start = sqrt(n);
    if (start * start < n) start++;
    for (ll i = start; i <= arr; ++i){
        ll cp = i * i;
        if (cp % n == 0){
            cout << cp / n;
            return 0;
        }
    }
    return 0;
}