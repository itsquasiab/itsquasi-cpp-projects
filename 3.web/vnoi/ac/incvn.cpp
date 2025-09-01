//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e4 + 6, MOD = 5e6;

ll a[ARR], st[4 * ARR][56], dp[56], p[56][ARR];

void update(int id, int l, int r, int u, int i, ll val){
    if (u < l || r < u) return;
    if (l == r){
        st[id][i] = (st[id][i] + val) % MOD;
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, i, val);
    update(id << 1 | 1, mid + 1, r, u, i, val);
    st[id][i] = (st[id << 1][i] + st[id << 1 | 1][i]) % MOD;
}

ll get(int id, int l, int r, int u, int v, int i){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id][i];
    int mid = l + r >> 1;
    return (get(id << 1, l, mid, u, v, i) + get(id << 1 | 1, mid + 1, r, u, v, i)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[1] = 1;
    for (int i = 1; i <= n; ++i){
        p[1][i] = 1;
    }
    for (int i = 2; i <= k; ++i){
        for (int j = 1; j <= n; ++j){
            ll t = get(1, 1, n + 1, a[j] + 1, n + 1, i - 1);
            p[i][j] = t;
            dp[i] = (dp[i] + t) % MOD;
            update(1, 1, n + 1, a[j], i - 1, p[i - 1][j]);
        }
    }
    cout << dp[k] % MOD;
    return 0;
}