// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "e"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll a[arr];

ll st[4 * arr], lazy[4 * arr], assign[4 * arr];

void build (int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
    st[id] = st[id << 1] + st[id << 1 | 1];

}

void push(int id, int l, int r){
    if (assign[id] == 1 && lazy[id] == 0) return;
    st[id] = (st[id] * assign[id]);
    st[id] = (st[id] + (r - l + 1) * lazy[id]);
    if (l != r){
        assign[id << 1] = (assign[id << 1] * assign[id]);
        assign[id << 1 | 1] = (assign[id << 1 | 1] * assign[id]);
        lazy[id << 1] = ((lazy[id << 1] * assign[id]) + lazy[id]);
        lazy[id << 1 | 1] = ((lazy[id << 1 | 1] * assign[id]) + lazy[id]);
    }
    assign[id] = 1;
    lazy[id] = 0;
}

void upd (int id, int l, int r, int u, int v, ll val, int type){
    push (id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        if (type == 2){
            lazy[id] = val;
            assign[id] = 0;
        }
        else {
            lazy[id] = (lazy[id] + val);
        }
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd (id << 1, l, mid, u, v, val, type);
    upd (id << 1 | 1, mid + 1, r, u, v, val, type);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

ll get (int id, int l, int r, int u, int v){
    push (id, l, r);
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
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= 4 * n; ++i) assign[i] = 1, lazy[i] = 0;
    build (1, 1, n);
    while (q--){
        int type;
        cin >> type;
        if (type == 1 || type == 2){
            int a, b;
            ll x;
            cin >> a >> b >> x;
            upd(1, 1, n, a, b, x, type);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << get(1, 1, n, a, b) << "\n";
        }
    }
    return 0;
}