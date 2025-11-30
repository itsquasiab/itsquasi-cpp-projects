//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];
ll st[4 * arr];

void upd(int id, int l, int r, int pos, ll val){
    if (pos < l || r < pos) return;
    if (l == r){
        st[id] = min(st[id], val);
        return;
    }
    int mid = l + r >> 1;
    upd(id << 1, l, mid, pos, val);
    upd(id << 1 | 1, mid + 1, r, pos, val);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MAX;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    return min(
        get(id << 1, l, mid, u, v),
        get(id << 1 | 1, mid + 1, r, u, v)
    );
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int i = 1; i <= n * 4; ++i){
        st[i] = LLONG_MAX;
    }
    upd(1, 1, n, a[1], b[1]);
    for (int i = 2; i <= n; ++i){
        ll x = get(1, 1, n, i - 1, n);
        upd(1, 1, n, a[i], x + b[i]);
    }
    cout << get(1, 1, n, n, n);
    return 0;
}