//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9, inf = LLONG_MAX;

ll a[arr], b[arr], st[4 * arr], pf[arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = pf[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return inf;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return min(g1, g2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort (b + 1, b + 1 + n);
    for (int i = 1; i <= m; ++i){
        int t = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        pf[i] = abs(a[i] - b[t]);
        if (t > 1)
        pf[i] = min(pf[i], abs(a[i] - b[t - 1]));
    }
    build(1, 1, m);
    while(k--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, m, l, r) << "\n";
    }
    return 0;
}