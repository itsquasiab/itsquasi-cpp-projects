// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "bai41"

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
    int n;
    cin >> n;
    vector<ll> odds, evens;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        if (a & 1) odds.push_back(a);
        else evens.push_back(a);
    }
    for (ll i : evens) cout << i << " ";
    for (ll i : odds) cout << i << " ";
    return 0;
}