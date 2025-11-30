#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll s;
ll a[arr];

/*ll st[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MIN;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    return min(
    get(id << 1, l, mid, u, v),
    get(id << 1 | 1, mid + 1, r, u, v)
    );
}*/

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("ability.inp","r")){
        freopen("ability.inp","r",stdin);
        freopen("ability.out","w",stdout);
    }
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (s--){
        int l, r;
        cin >> l >> r;
        vector<ll> kien;
        for (int i = l; i <= r; ++i) kien.push_back(a[i]);
        sort (kien.begin(), kien.end());
        ll res = kien[kien.size() - 1] + 1;
        int i = 0;
        for (ll v : kien){
            //cout << i << " " << v << "\n";
            if (i != v){
                res = i;
                break;
            }
            i++;
        }
        cout << res << "\n";
    }
    return 0;
}
