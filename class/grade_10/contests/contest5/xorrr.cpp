//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr], st[4 * arr], lazy[4 * arr], cnt[4 * arr][21];

void push(int id, int l, int r){
    if (lazy[id]){
        for (int b = 0; b <= 20; b++) {
            if ((lazy[id] >> b) & 1) {
                cnt[id][b] = (r - l + 1) - cnt[id][b];
            }
        }
        if (l != r){
            lazy[id << 1] ^= lazy[id];
            lazy[id << 1 | 1] ^= lazy[id];
        }
        lazy[id] = 0;
    }
}

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void update(int id, int l, int r, int u, int v, ll val){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] ^= val;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

ll get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return g1 + g2;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    /*for (int i = 1; i <= 4 * n; ++i){
        lazy[i] = -1;
    }*/
    build(1, 1, n);
    cin >> q;
    while (q--){
        int t;
        cin >> t;
        if (t == 1){
            ll u, v;
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << "\n";
        }
        else {
            ll u, v, val;
            cin >> u >> v >> val;
            update(1, 1, n, u, v, val);
        }
    }
    return 0;
}