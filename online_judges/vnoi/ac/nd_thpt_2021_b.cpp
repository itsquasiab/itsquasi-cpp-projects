// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#include <vector>
#define ll long long
#define task "sdb"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<ll, int> cnt;

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
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<ll> res;
    for (int i = 1; i <= n; ++i){
        //cout << i.first << "\n";
        if (cnt[a[i]] == 1) res.push_back(a[i]);
    }
    cout << res.size() << "\n";
    for (ll i : res){
        cout << i << "\n";
    }
    return 0;
}