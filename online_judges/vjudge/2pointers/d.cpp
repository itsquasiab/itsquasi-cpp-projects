// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define task "d"

using namespace std;

const ll arr = 30006, mod = 1e9 + 7;

ll a[arr];
vector<ll> st[4 * arr];

void build (int id, int l, int r){
    if (l == r){
        st[id].push_back(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    int i = 0, j = 0;
    while (i < st[id << 1].size() && j < st[id << 1 | 1].size()){
        if (st[id << 1][i] <= st[id << 1 | 1][j]){
            st[id].push_back(st[id << 1][i]);
            i++;
        }
        else{
            st[id].push_back(st[id << 1 | 1][j]);
            j++;
        }
    }
    while (i < st[id << 1].size()) st[id].push_back(st[id << 1][i]), i++;
    while (j < st[id << 1 | 1].size()) st[id].push_back(st[id << 1 | 1][j]), j++;
}

ll get(int id, int l, int r, int u, int v, int k){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id].end() - upper_bound(st[id].begin(), st[id].end(), k);
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v, k) + get(id << 1 | 1, mid + 1, r, u, v, k);
}

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
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--){
        int i, j;
        ll k;
        cin >> i >> j >> k;
        cout << get(1, 1, n, i, j, k) << "\n";
    }
    return 0;
}