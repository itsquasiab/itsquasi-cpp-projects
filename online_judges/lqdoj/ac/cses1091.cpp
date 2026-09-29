// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <set>
#define ll long long
#define task "cses1091"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

multiset<ll> price;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        price.insert(a);
    }
    while (m--){
        ll x;
        cin >> x;
        auto it = price.upper_bound(x);
        if (it == price.begin()) cout << "-1\n";
        else {
            cout << *(--it) << "\n";
            price.erase(it);
        }
    }
    return 0;
}