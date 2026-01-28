// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <climits>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n;
ll a[arr];
int q;
struct tree
{
    ll sum, pre, sur, bst;
} st[4 * arr];

tree merge(tree a, tree b){
    tree res;
    res.sum = a.sum + b.sum;
    res.pre = max(a.pre, a.sum + b.pre);
    res.sur = max(b.sur, b.sum + a.sur);
    res.bst = max(max(a.bst, b.bst), a.sur + b.pre);
    return res;
}

void build(int id, int l, int r){
    if (l == r){
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

tree get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return merge(
        get(id << 1, l, mid, u, v),
        get(id << 1 | 1, mid + 1, r, u, v)
    );
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r).bst << "\n";
    }
    return 0;
}