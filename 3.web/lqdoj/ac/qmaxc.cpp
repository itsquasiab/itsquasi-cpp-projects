//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll st[4 * arr], lazy[4 * arr];

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

void update(int id, int l, int r, int u, int v, ll val){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] += val;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return inf;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return max(g1, g2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--){
        ll l, u, v;
        cin >> l >> u >> v;
        if (l == 0){
            ll x;
            cin >> x;
            update(1, 1, n, u, v, x);
        }
        else cout << get(1, 1, n, u, v) << "\n";
    }
    return 0;
}