//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = INT_MIN;

struct tree{
    ll ans, l, r, sum;
} st[4 * arr];
ll a[arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id].ans = max({st[id << 1].ans, st[id << 1 | 1]. ans, st[id << 1].r + st[id << 1 | 1].l});
    st[id].l = max(st[id << 1].l, st[id << 1 | 1].l + st[id << 1].sum);
    st[id].r = max(st[id << 1 | 1].r, st[id << 1].r + st[id << 1 | 1].sum);
    st[id].sum = st[id << 1].sum + st[id << 1 | 1].sum;
}

tree get(int id, int l, int r, int v, int u){
    if (v < l || r < u) return {inf, inf, inf, inf};
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    tree g1 = get(id << 1, l, mid, v, u);
    tree g2 = get(id << 1 | 1, mid + 1, r, v, u);
    tree res;
    res.ans = max({g1.ans, g2. ans, g1.r + g2.l});
    res.l = max(g1.l, g2.l + g1.sum);
    res.r = max(g2.r, g1.r + g2.sum);
    res.sum = g1.sum + g2.sum;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, r, l).ans << "\n";
    }
    return 0;
}