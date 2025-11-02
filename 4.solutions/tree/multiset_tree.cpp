//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

int m, n;
ll a[arr];
multiset<ll> st[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        st[id].insert(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id].insert(st[id << 1].begin(), st[id << 1].end());
    st[id].insert(st[id << 1 | 1].begin(), st[id << 1 | 1].end());
}

void update(int id, int l, int r, int i, int old, int val){
    if (i < l || r < i) return;
    if (l == r){
        st[id].clear();
        st[id].insert(val);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, i, old, val);
    update(id << 1 | 1, mid + 1, r, i, old, val);
    st[id].erase(st[id].find(old));
    st[id].insert(val);
}

int get(int id, int l, int r, int u, int v, int k){
    if (v < l || r < u) return INT_MAX;
    if (l >= u && r <= v) {
        auto it = st[id].lower_bound(k);
        if (it == st[id].end()) return INT_MAX;
        return *it;
    }
    int mid = l + r >> 1;
    return min(
        get(id << 1, l, mid, u, v, k),
        get(id << 1 | 1, mid + 1, r, u, v, k)
    );
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--){
        int l, u, v, k;
        cin >> l;
        if (l == 1){
            cin >> u >> k;
            update(1, 1, n, u, a[u], k);
            a[u] = k;
        }
        else {
            cin >> u >> v >> k;
            int ans = get(1, 1, n, u, v, k);
            cout << ((ans == INT_MAX) ? -1 : ans) << "\n";
        }
    }
    return 0;
}