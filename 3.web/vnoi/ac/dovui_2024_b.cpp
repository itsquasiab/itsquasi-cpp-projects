//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], st[4 * arr], lazy[4 * arr];

void push(int id, int l, int r){
    if (lazy[id]){
        st[id] = (r - l + 1) - st[id];
        if (l != r){
            lazy[id << 1] ^= 1;
            lazy[id << 1 | 1] ^= 1;
        }
        lazy[id] = 0;
    }
}

void upd(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] ^= 1;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    upd(id << 1, l, mid, u, v);
    upd(id << 1 | 1, mid + 1, r, u, v);
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
    cin >> n >> q;
    while (q--){
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 0){
            upd(1, 0, n - 1, a, b);
        }
        else {
            cout << get(1, 0, n - 1, a, b) << "\n";
        }
    }
    return 0;
}