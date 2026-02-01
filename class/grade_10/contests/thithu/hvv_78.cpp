//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <climits>
#define ll long long

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll n, x, y;
ll a[arr];
ll res = 0;
ll stmx[4 * arr], stmn[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        stmx[id] = stmn[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    stmx[id] = max(stmx[id << 1], stmx[id << 1 | 1]);
    stmn[id] = min(stmn[id << 1], stmn[id << 1 | 1]);
}

ll getmx(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MIN;
    if (u <= l && r <= v) return stmx[id];
    int mid = l + r >> 1;
    return max(
        getmx(id << 1, l, mid, u, v),
        getmx(id << 1 | 1, mid + 1, r, u, v)
    );
}

ll getmn(int id, int l, int r, int u, int v){
    if (v < l || r < u) return LLONG_MAX;
    if (u <= l && r <= v) return stmn[id];
    int mid = l + r >> 1;
    return min(
        getmn(id << 1, l, mid, u, v),
        getmn(id << 1 | 1, mid + 1, r, u, v)
    );
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    ll t = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (getmx(1, 1, n, i, j) == x && getmn(1, 1, n, i, j) == y) t++;
        }
    }
    cout << t;
    return 0;
}