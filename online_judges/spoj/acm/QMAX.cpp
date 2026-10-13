// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "QMAX"

using namespace std;

const ll arr = 50006, mod = 1e9 + 7;

ll a[arr], st[4 * arr], lazy[4 * arr];

void push(int id, int l, int r){
    if (lazy[id]){
        st[id] += lazy[id];
        if (l != r){
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void upd(int id, int l, int r, int u, int v, ll val){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] += val;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, u, v, val);
    upd(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return -1e18;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
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
    while (m--){
        int u, v;
        ll k;
        cin >> u >> v >> k;
        upd(1, 1, n, u, v, k);
    }
    int p;
    cin >> p;
    while (p--){
        int u, v;
        cin >> u >> v;
        cout << get(1, 1, n, u, v) << "\n";
    }
    return 0;
}