//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], st[ARR * 4];

void build (int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}

ll get (int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MAX;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return min(g1, g2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << "\n";
    }
    return 0;
}