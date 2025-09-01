//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 7;

ll a[ARR], st[4 * ARR], lazy[4 * ARR];

void push(int id, int l, int r){
    if (lazy[id]){
        st[id] = max(st[id], lazy[id]);
        if (l != r){
            lazy[id << 1] = max(lazy[id << 1], lazy[id]);
            lazy[id << 1 | 1] = max(lazy[id << 1 | 1], lazy[id]);
        }
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, ll val){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] = max(lazy[id], val);
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = (st[id << 1] + st[id << 1 | 1]);
}

ll get(int id, int l, int r, int i){
    push(id, l, r);
    if (i < l || r < i) return 0;
    if (l == r) return st[id];
    int mid = l + r >> 1;
    ll x = get(id << 1, l, mid, i);
    if (x != 0) return x;
    return get(id << 1 | 1, mid + 1, r, i);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    while (q--){
        ll l;
        cin >> l;
        if (l == 1){ 
            ll u, v, x;
            cin >> u >> v >> x;
            update(1, 1, n, u, v, x);
        }
        else {
            ll i;
            cin >> i;
            cout << get(1, 1, n, i) << "\n";
        }
    }
    return 0;
}