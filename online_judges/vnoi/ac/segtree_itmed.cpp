// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "segtree_itmed"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll dp[arr];
ll st[4 * arr];

void upd(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, i, val);
    upd(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return -1e18;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[0] = 0;
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        ll mxres = get(1, 1, n, max(i - k, 1), max(i - 1, 1));
        dp[i] = a[i] + max(0ll, mxres);
        res = max(res, dp[i]);
        //cout << res << " ";
        upd(1, 1, n, i, dp[i]);
    }
    cout << res;
    return 0;
}