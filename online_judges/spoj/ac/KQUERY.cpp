//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr];
vector<ll> st[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        st[id].push_back(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id].resize(st[id << 1].size() + st[id << 1 | 1].size());
    merge(st[id << 1].begin(), st[id << 1].end(), st[id << 1 | 1].begin(), st[id << 1 | 1].end(), st[id].begin());
}

ll get(int id, int l, int r, int u, int v, int k){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id].end() - upper_bound(st[id].begin(), st[id].end(), k);
    int mid = l + r >> 1;
    ll get1 = get(id << 1, l, mid, u, v, k);
    ll get2 = get(id << 1 | 1, mid + 1, r, u, v, k);
    return get1 + get2;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--){
        ll i, j, k;
        cin >> i >> j >> k;
        cout << get(1, 1, n, i, j, k) << "\n";
    }
    return 0;
}