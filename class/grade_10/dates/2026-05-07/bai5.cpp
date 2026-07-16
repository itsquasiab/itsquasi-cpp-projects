// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <utility>
#define ll long long
#define task "bai5"

using namespace std;

const ll arr = 5e5 + 6, mod = 1e9 + 7;

pair<ll, int> a[arr];
ll b[arr];

bool value_sort(pair<ll, int> a, pair<ll, int> b){
    return a.first < b.first;
}
bool index_sort(pair<ll, int> a, pair<ll, int> b){
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
    for (int j = 1; j <= m; ++j) cin >> b[j];
    sort (b + 1, b + 1 + m);
    sort (a + 1, a + 1 + n, value_sort);
    ll pfs = 0;
    int j = 1;
    for (int i = 1; i <= n; ++i){
        a[i].first += pfs;
        while (j <= m){
            if (a[i].first >= b[j]){
                a[i].first += b[j];
                pfs += b[j];
                j++;
            }
            else break;
        }
    }
    sort (a + 1, a + 1 + n, index_sort);
    for (int i = 1; i <= n; ++i) cout << a[i].first << " ";
    return 0;
}