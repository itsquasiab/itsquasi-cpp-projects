// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "sale"

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
    ll n, k, p;
    cin >> n >> k >> p;
    ll sets = 36 / (p + 1), remains = 36 % (p + 1);
    ll res = remains * k + (sets * p * k);
    cout << res;
    return 0;
}