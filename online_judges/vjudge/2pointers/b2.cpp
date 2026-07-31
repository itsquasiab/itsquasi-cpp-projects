// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long
#define task "b"

using namespace std;

const ll arr = 5006, mod = 1e9 + 7;

ll a[arr];
unordered_map<ll, int> first_pos;

struct sol
{
    int a, b, c;
};

vector<sol> res;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (!first_pos.count(a[i])) first_pos[a[i]] = i;
    }
    bool found = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            for (int k = j + 1; k <= n; ++k){
                if (a[i] + a[j] + a[k] == x){
                    res.push_back({i, j, k});
                    found = 1;
                }
            }
        }
    }
    if (found) {
        for (auto i : res){
            cout << i.a << " " << i.b << " " << i.c << "\n";
        }
    }
    else cout << "IMPOSSIBLE";
    return 0;
}