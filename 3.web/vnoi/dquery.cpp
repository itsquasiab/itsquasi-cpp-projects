// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
ll a[arr];
ll st[4 * arr];

vector<pair<int, int>> query;

bool sorter(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void upd(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, i, val);
    upd(id << 1 | 1, mid + 1, r, i, val);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
    }
    sort(query.begin(), query.end(), sorter);
    return 0;
}