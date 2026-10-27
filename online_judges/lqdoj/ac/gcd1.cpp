// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#define ll long long
#define task "gcd1"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

vector<ll> a;

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
    for (int i = 1; i <= n; ++i){
        int type, x;
        cin >> type >> x;
        if (type == 1){
            a.push_back(x);
        }
        else {
            auto it = find(a.begin(), a.end(), x);
            if (it != a.end()) a.erase(it);
        }
        ll res = 0;
        for (ll i : a) res = gcd(res, i);
        cout << res << "\n";
    }
    return 0;
}