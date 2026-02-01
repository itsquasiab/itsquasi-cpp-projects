//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

struct tree{
    ll sum, pref;
}st[4 * arr];

ll a[arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = {a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id].sum = st[id << 1].sum + st[id << 1 | 1].sum;
    st[id].pref = max(st[id << 1].pref, st[id << 1].sum + st[id << 1 | 1].pref);
}

void upd(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = {val, val};
        return;
    }
    int mid = l + r >> 1;
    upd(id << 1, l, mid, i, val);
    upd(id << 1 | 1, mid + 1, r, i, val);
    st[id].sum = st[id << 1].sum + st[id << 1 | 1].sum;
    st[id].pref = max(st[id << 1].pref, st[id << 1].sum + st[id << 1 | 1].pref);
}

tree get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return {0, 0};
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    tree g1 = get(id << 1, l, mid, u, v);
    tree g2 = get(id << 1 | 1, mid + 1, r, u, v); 
    tree res;
    res.sum = g1.sum + g2.sum;
    res.pref = max(g1.pref, g1.sum + g2.pref);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--){
        ll l, u, v;
        cin >> l >> u >> v;
        if (l == 1){
            upd(1, 1, n, u, v);
        }
        else {
            cout << max(0ll, get(1, 1, n, u, v).pref) << "\n";
        }
    }
    return 0;
}