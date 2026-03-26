// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#define ll long long
#define task "max_and_occurrences"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

pair<int, int> t[4*arr];
int n, q;
ll a[arr];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-1e18, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    cin >> q;
    while (q--){
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) update(1, 1, n, x, y);
        else{
            pair<int, int> get = get_max(1, 1, n, x, y);
            cout << get.first << ' ' << get.second << '\n';
        }
    }
    return 0;
}