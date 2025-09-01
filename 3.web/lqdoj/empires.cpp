//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], st[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return inf;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    while (q--){
        ll l, r;
        cin >> l >> r;
        
    }
    return 0;
}