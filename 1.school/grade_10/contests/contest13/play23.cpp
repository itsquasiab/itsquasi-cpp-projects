// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <climits>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 5e6 + 6, mod = 1e9 + 7;

ll a[arr], dp[arr];
ll st[4 * arr];

void update(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]); 
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MIN;
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
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], dp[i] = LLONG_MIN;

    if (k == n){
        dp[1] = a[1];
        for (int i = 2; i < n; ++i){
            dp[i] = dp[i - 1] + (a[i] > 0 ? a[i] : 0);
        }
        cout << dp[n - 1] + a[n];
    }
    else {
        dp[1] = a[1];
        update(1, 1, n, 1, dp[1]);
        for (int i = 2; i <= n; ++i){
            dp[i] = get(1, 1, n, max(i - k, 1), i - 1) + a[i];
            update(1, 1, n, i, dp[i]);
        }
        cout << dp[n];
    }
    return 0;
}