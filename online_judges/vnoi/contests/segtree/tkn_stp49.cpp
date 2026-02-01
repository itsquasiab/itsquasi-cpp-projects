//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 7;

ll a[ARR], st[4 * ARR], lazy[4 * ARR];

void push(int id, int l, int r){
    if (lazy[id] != -1){
        st[id] = (r - l + 1) * lazy[id];
        if (l != r){
            lazy[id << 1] = lazy[id];
            lazy[id << 1 | 1] = lazy[id];
        }
        lazy[id] = -1;
    }
}

void update(int id, int l, int r, int u, int v, ll val){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] = val;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    st[id] = (st[id << 1] + st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return (g1 + g2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= 4 * n; ++i){
        lazy[i] = -1;
    }
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