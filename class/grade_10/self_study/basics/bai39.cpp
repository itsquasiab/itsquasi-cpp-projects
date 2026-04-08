// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "bai39"

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
    vector<ll> odds;
    while (n--){
        ll a;
        cin >> a;
        if (a & 1) odds.push_back(a);
    }
    cout << odds.size() << "\n";
    for (ll i : odds){
        cout << i << "\n";
    }
    return 0;
}