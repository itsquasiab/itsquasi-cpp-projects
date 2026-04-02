// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#define ll long long
#define task "atcoder_dp_q"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

int n;
pair<ll, ll> a[arr];
ll dp[arr];
pair<ll, ll> st[4 * arr];

void upd(int id, int l, int r, int i, ll val1, ll val2){
    if (i < l || r < i) return;
    if (l == r){
        st[id].first = val1;
        st[id].second = val2;
        return;
    }
    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, i, val1, val2);
    upd(id << 1 | 1, mid + 1, r, i, val1, val2);
    st[id].first = min(st[id << 1].first, st[id << 1 | 1].first);
    st[id].second = max(st[id << 1].second, st[id << 1 | 1].second);
}

ll get(int id, int l, int r, int u, int v, int req){
    if (v < l || r < u || st[id].first >= req) return -1e18;
    if (l == r) return st[id].second;
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v, req), get(id << 1 | 1, mid + 1, r, u, v, req));
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
        dp[i] = a[i].second;
        //replace this for loop with a segment tree implementation
        ll getmx = get(1, 1, n, 1, i, a[i].first);
        dp[i] = max(dp[i], getmx + a[i].second);
        /*for (int j = 1; j < i; ++j){
            if (a[j].first < a[i].first) dp[i] = max(dp[i], dp[j] + a[i].second);
        }*/
        res = max(res, dp[i]);
        upd(1, 1, n, i, a[i].first, dp[i]);
    }
    cout << res;
    return 0;
}
