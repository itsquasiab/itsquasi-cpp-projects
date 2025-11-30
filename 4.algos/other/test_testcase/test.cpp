//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n;
ll a[arr];
ll st1[4 * arr], st2[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        st1[id] = a[l];
        st2[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
    st1[id] = max(st1[id << 1], st1[id << 1 | 1]);
    st2[id] = min(st2[id << 1], st2[id << 1 | 1]);
}

ll getmax(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MIN;
    if (u <= l && r <= v) return st1[id];
    int mid = l + r >> 1;
    return max(
        getmax(id << 1, l, mid, u, v),
        getmax(id << 1 | 1, mid + 1, r, u, v)
    );
}

ll getmin(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MAX;
    if (u <= l && r <= v) return st2[id];
    int mid = l + r >> 1;
    return min(
        getmin(id << 1, l, mid, u, v),
        getmin(id << 1 | 1, mid + 1, r, u, v)
    );
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    ll s = 0;
    /*for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            s += getmax(1, 1, n, i, j) - getmin(1, 1, n, i, j);
        }
    }*/
    for (int i = 2; i <= n; ++i){
        s += getmax(1, 1, n, 1, i) - getmin(1, 1, n, 1, i);
    }
    for (int i = 1; i < n; ++i){
        s += getmax(1, 1, n, i, n) - getmin(1, 1, n, i, n);
    }
    cout << s;
    return 0;
}