//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

struct tree{
    ll l, r, ans, sum;
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
    st[id].ans = max({st[id << 1].ans, st[id << 1 | 1].ans, st[id << 1].r + st[id << 1 | 1].l});
    st[id].l = max(st[id << 1].l, st[id << 1 | 1].l + st[id << 1].sum);
    st[id].r = max(st[id << 1 | 1].r, st[id << 1].r + st[id << 1 | 1].sum);
    st[id].sum = st[id << 1].sum + st[id << 1 | 1].sum;
}

void upd(int id, int l, int r, int i, ll x){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = {x, x, x, x};
        return;
    }
    int mid = l + r >> 1;
    upd(id << 1, l, mid, i, x);
    upd(id << 1 | 1, mid + 1, r, i, x);
    st[id].ans = max({st[id << 1].ans, st[id << 1 | 1].ans, st[id << 1].r + st[id << 1 | 1].l});
    st[id].l = max(st[id << 1].l, st[id << 1 | 1].l + st[id << 1].sum);
    st[id].r = max(st[id << 1 | 1].r, st[id << 1].r + st[id << 1 | 1].sum);
    st[id].sum = st[id << 1].sum + st[id << 1 | 1].sum;
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
    while (q--){
        ll i, k;
        cin >> i >> k;
        upd(1, 1, n, i, k);
        cout << max(0ll, st[1].ans) << "\n";
    }
    return 0;
}