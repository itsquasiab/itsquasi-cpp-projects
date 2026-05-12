// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define task "atcoder_dp_q"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

int n;
pair<ll, ll> a[arr];
ll dp[arr], st[arr * 4];

void upd(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = max(st[id], val);
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, i, val);
    upd(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return max(
    get(id << 1, l, mid, u, v),
    get(id << 1 | 1, mid + 1, r, u, v)
    );
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first;
    for (int i = 1; i <= n; ++i) cin >> a[i].second;
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        ll j = get(1, 1, n, 1, a[i].first - 1);
        dp[i] = j + a[i].second;
        upd(1, 1, n, a[i].first, dp[i]);
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}
