// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "lc_ts10_24_c"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

int st[2 * arr];
bool a[arr];
int n, k;

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
    st[id] = (st[id << 1] + st[id << 1 | 1]);
}

void upd(int id, int l, int r, int i, bool val){
    if (r < i || l > i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    upd (id << 1, l, mid, i, val);
    upd (id << 1 | 1, mid + 1, r, i, val);
    st[id] = (st[id << 1] + st[id << 1 | 1]);
}

/*ll get(int id, int l, int r, int u, int v){
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v));
}*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) a[i] = 1;
    build (1, 1, n);
    while (k--){
        ll x, y;
        cin >> x >> y;
        swap(a[x], a[y]);
        if (x <= n) upd(1, 1, n, x, a[x]);
        if (y <= n) upd(1, 1, n, y, a[y]);
        cout << st[1] << "\n";
    }
    return 0;
}
