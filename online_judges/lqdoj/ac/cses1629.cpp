//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

pair<ll, ll> a[arr];

bool sorter(pair<ll, ll> a, pair<ll, ll> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /*if (fopen(task".inp","r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }*/
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort (a + 1, a + 1 + n, sorter);
    int res = 1;
    ll last = a[1].second;
    for (int i = 2; i <= n; ++i){
        if (last <= a[i].first) res++, last = a[i].second;
    }
    cout << res;
    return 0;
}