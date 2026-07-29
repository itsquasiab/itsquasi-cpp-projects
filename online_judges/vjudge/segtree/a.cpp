// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "a"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll st[4 * arr], a[arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void upd(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    upd (id << 1, l, mid, i, val);
    upd (id << 1 | 1, mid + 1, r, i, val);
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
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--){
        int order;
        cin >> order;
        if (order == 1){
            int k;
            ll u;
            cin >> k >> u;
            upd(1, 1, n, k, u);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << get(1, 1, n, a, b) << "\n";
        }
    }
    return 0;
}