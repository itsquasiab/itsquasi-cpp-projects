// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "ip"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

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
    for (int j = 1; j <= n; ++j){
        ll mx = 0;
        unordered_map<ll, bool> mp;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            mx = max(mx, a[i]);
            mp[a[i]] = 1;
        }
        bool found = 0;
        for (int i = 1; i <= mx; ++i){
            if (!mp[i]){
                cout << i << "\n";
                found = 1;
                break;
            }
        }
        if (!found) cout << mx + 1 << "\n";
    }
    return 0;
}