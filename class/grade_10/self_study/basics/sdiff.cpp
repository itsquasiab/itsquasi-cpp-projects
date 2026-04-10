// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define task "sdiff"

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
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll mn = 1e18;
    sort (a + 1, a + 1 + n);
    for (int i = 1; i < n; ++i){
        mn = min(mn, abs(a[i + 1] - a[i]));
    }
    vector<ll> valid;
    for (int i = 1; i < n; ++i){
        if (abs(a[i + 1] - a[i]) == mn){
            valid.push_back(a[i + 1]);
            valid.push_back(a[i]);
        }
    }
    sort (valid.begin(), valid.end());
    for (auto i : valid) cout << i << " ";
    return 0;
}