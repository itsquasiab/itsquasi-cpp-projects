// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define task "456A"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool sorter(pair<ll, ll> a, pair<ll, ll> b){
    return a.first < b.first;
}

pair<ll, ll> a[arr];

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
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; ++i){
        if (a[i - 1].second >= a[i].second){
            cout << "Happy Alex";
            return 0;
        }
    }
    cout << "Poor Alex";
    return 0;
}