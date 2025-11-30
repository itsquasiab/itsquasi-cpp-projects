#include<bits/stdc++.h>
#define ll long long
#define tname "team24"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a[arr];
ll st[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
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
    if (fopen(tname".inp", "r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    ll t = n - 1;
    for (int i = 3; i <= n; ++i){
        for (int j = 1; j < i - 1; ++j){
            ll mx = max(a[i], a[j]);
            if (get(1, 1, n, j + 1, i - 1) < mx) t++;
        }
    }
    cout << t;
    return 0;
}
