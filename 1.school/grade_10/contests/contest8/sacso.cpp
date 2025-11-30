//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string s;

struct tree{
    char l, r;
    ll d;
    char lazy = ' ';
}st[4 * arr];

void build(int id, int l, int r){
    if (l == r){
        st[id].l = s[l];
        st[id].r = s[r];
        st[id].d = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build (id << 1, l, mid);
    build (id << 1 | 1, mid + 1, r);
    st[id].l = st[id << 1].l;
    st[id].r = st[id << 1 | 1].r;
    st[id].d = st[id << 1].d + st[id << 1 | 1].d + (st[id << 1].r != st[id << 1 | 1].l);
}

void push(int id, int l, int r){
    if (st[id].lazy != ' ') {
        st[id].l = st[id].r = st[id].lazy;
        st[id].d = 0;
        if (l != r){
            st[id << 1].lazy = st[id].lazy;
            st[id << 1 | 1].lazy = st[id].lazy;
        }
    }
    st[id].lazy = ' ';
}

void update(int id, int l, int r, int u, int v, char c){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        st[id].lazy = c;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, c);
    update(id << 1 | 1, mid + 1, r, u, v, c);
    st[id].l = st[id << 1].l;
    st[id].r = st[id << 1 | 1].r;
    st[id].d = st[id << 1].d + st[id << 1 | 1].d + (st[id << 1].r != st[id << 1 | 1].l);
}

tree get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return {'#', '#', 0, ' '};
    if (u <= l && r <= v) return st[id];

    int mid = (l + r) >> 1;
    tree left = get(id << 1, l, mid, u, v);
    tree right = get(id << 1 | 1, mid + 1, r, u, v);

    if (left.l == '#') return right;
    if (right.l == '#') return left;

    tree res;
    res.l = left.l;
    res.r = right.r;
    res.d = left.d + right.d + (left.r != right.l);
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, t;
    cin >> n >> t >> s;
    s = ' ' + s;
    build(1, 1, n);
    while (t--){
        string input;
        cin >> input;
        if (input == "get"){
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r).d + 1 << "\n";
        }
        else {
            int l, r;
            char c;
            cin >> l >> r >> c;
            update(1, 1, n, l, r, c);
        }
    }
    return 0;
}