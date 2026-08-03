// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <set>
#define ll long long
#define task "e"

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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int n2 = n / 2;
        vector<ll> b;
        for (int i = 1; i <= n2; ++i){
            ll x;
            cin >> x;
            b.push_back(x);
        }
        // check if b is valid
        bool invalid = 0;
        vector<bool> used(n + 1, 0);
        for (int i = 0; i < n2; ++i){
            if (used[b[i]]){
                invalid = 1;
                break;
            }
            used[b[i]] = 1;

        }
        if (invalid){
            cout << -1 << "\n";
            continue;
        }
        // create set
        set<ll> s;
        for (int i = 1; i <= n; ++i){
            if (!used[i]) s.insert(i);
        }
        // connect pair
        vector<ll> p(n + 1, 0);
        for (int i = b.size(); i >= 1; --i){
            auto it = s.lower_bound(b[i - 1]);
            if (it == s.begin()){
                invalid = 1;
                break;
            }
            --it;
            ll x = *it;
            // assign
            p[2 * i - 1] = x;
            p[2 * i] = b[i - 1];
            s.erase(it);
        }
        if (invalid){
            cout << -1 << "\n";
            continue;
        }
        for (int i = 1; i <= n; ++i){
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}