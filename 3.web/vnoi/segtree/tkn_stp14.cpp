//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], st[4 * ARR];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}

void update(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1 | 1, mid + 1, r, i, val);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MAX;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build (1, 1, n);
    while (q--){
        ll l, u, v;
        cin >> l >> u >> v;
        if (l == 1) a[u] = v, update(1, 1, n, u, v);
        else{
            ll gm = get(1, 1, n, u, v);
            cout << gm << " ";
            ll t = 0;
            for (int i = u; i <= v; ++i){
                if (a[i] == gm) t++;
            }
            cout << t << "\n";
        }
    }
    return 0;
}