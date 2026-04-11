// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define task "bwpoints"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

pair<ll, bool> a[arr];

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
        cin >> a[i].first;
        a[i].second = 1;
    }
    for (int i = n + 1; i <= n * 2; ++i){
        cin >> a[i].first;
        a[i].second = 0;
    }
    sort(a + 1, a + 1 + 2 * n);
    ll res = 0;
    for (int i = 2; i <= n * 2; ++i){
        if (a[i].second != a[i - 1].second) res++, i++;
    }
    cout << res;
    return 0;
}