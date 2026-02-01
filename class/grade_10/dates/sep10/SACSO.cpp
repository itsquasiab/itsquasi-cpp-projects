//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

struct tree{
    char lch, rch;
    ll val;
} st[arr];
char lazy[arr];
int n, q;
string a;

tree merge(tree l, tree r){
    if (l.lch == 0) return r;
    if (r.lch == 0) return l;
    tree res;
    res.lch = l.lch;
    res.rch = r.rch;
    res.val = l.val + r.val + (l.rch != r.lch);
    return res;
}

void build(int id, int l, int r){
    if (l == r){
        st[id].lch = st[id].rch = a[l];
        st[id].val = 0;
        lazy[id] = ' ';
        return;
    }
    int mid = l + r >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
    st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

void push(int id, int l, int r){
    if (lazy[id] != ' '){
    st[id].lch = st[id].rch = lazy[id];
    st[id].val = 0;
        if (l != r){
            lazy[id << 1] = lazy[id << 1 | 1] = lazy[id];
        }
    lazy[id] = ' ';
    }
}

void upd(int id, int l, int r, int u, int v, char c){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] = c;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    upd (id << 1, l, mid, u, v, c);
    upd (id << 1 | 1, mid + 1, r, u, v, c);
    st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

tree get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return {0, 0, 0};
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    tree g1 = get(id << 1, l, mid, u, v);
    tree g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return merge(g1, g2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q >> a;
    a = ' ' + a;
    build (1, 1, n);
    while (q--){
        string l;
        cin >> l;
        if (l == "change"){
            ll u, v;
            char c;
            cin >> u >> v >> c;
            upd(1, 1, n, u, v, c);
        }
        else {
            ll u, v;
            cin >> u >> v;
            cout << get(1, 1, n, u, v).val << "\n";
        }
    }
    return 0;
}