#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 5e6 + 6, mod = 1e9 + 7;

int n, k;
ll a[arr], dp[arr];

ll st[4 * arr];

void update(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MIN;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    return max(
    get(id << 1, l, mid, u, v),
    get(id << 1 | 1, mid + 1, r, u, v)
    );
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("play.inp","r")){
        freopen("play.inp","r",stdin);
        freopen("play.out","w",stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0] = 0;
    update(1, 0, n, 0, dp[0]);
    for (int i = 1; i <= n; ++i){
        //cout << dp[i] << " ";
        dp[i] = get(1, 0, n, max(0, i - k), i - 1) + a[i];
        //cout << dp[i] << " ";
        update(1, 0, n, i, dp[i]);
        /*for (int j = max(i - k, 0); j < i; ++j){
            dp[i] = max(dp[i], dp[j] + a[i]);
        }*/
    }
    cout << dp[n];
    return 0;
}
