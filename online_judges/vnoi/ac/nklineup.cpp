//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR];
pair<ll, ll> st[4 * ARR];

void build(int id, int l, int r){
    if (l == r){
        st[id].first = a[l];
        st[id].second = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id].first = max(st[id << 1].first, st[id << 1 | 1].first);
    st[id].second = min(st[id << 1].second, st[id << 1 | 1].second);
}

ll get1(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MIN;
    if (u <= l && r <= v) return st[id].first;
    int mid = l + r >> 1;
    ll g1 = get1(id << 1, l, mid, u, v);
    ll g2 = get1(id << 1 | 1, mid + 1, r, u, v);
    return max(g1, g2);
}

ll get2(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MAX;
    if (u <= l && r <= v) return st[id].second;
    int mid = l + r >> 1;
    ll g1 = get2(id << 1, l, mid, u, v);
    ll g2 = get2(id << 1 | 1, mid + 1, r, u, v);
    return min(g1, g2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << get1(1, 1, n, l, r) - get2(1, 1, n, l, r) << "\n";
    }
    return 0;
}