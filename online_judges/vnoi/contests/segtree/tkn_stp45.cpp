//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 7;

ll a[ARR], st[4 * ARR], lazy[4 * ARR];

void push(int id, int l, int r){
    if (lazy[id] != 1){
        st[id] *= lazy[id];
        st[id] %= MOD;
        if (l != r){
            lazy[id << 1] = lazy[id << 1] * lazy[id] % MOD;
            lazy[id << 1 | 1] = lazy[id << 1 | 1] * lazy[id] % MOD;
        }
        lazy[id] = 1;
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
    st[id] = (st[id << 1] + st[id << 1 | 1]) % MOD;
}

void update(int id, int l, int r, int u, int v, ll val){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] *= val;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = (st[id << 1] + st[id << 1 | 1]) % MOD;
}

ll get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return (g1 + g2) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        a[i] = 1;
    }
    for (int i = 1; i <= 4 * n; ++i){
        lazy[i] = 1;
    }
    build(1, 1, n);
    while (q--){
        ll l, u, v;
        cin >> l >> u >> v;
        if (l == 1){ 
            ll x;
            cin >> x;
            update(1, 1, n, u, v, x);
        }
        else {
            cout << get(1, 1, n, u, v) << "\n";
        }
    }
    return 0;
}