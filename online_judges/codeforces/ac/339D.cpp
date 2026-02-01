//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr], st[4 * arr];

void build(int id, int l, int r, bool op){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid, op ^ 1);
    build(id << 1 | 1, mid + 1, r, op ^ 1);
    if (!op) st[id] = (st[id << 1] | st[id << 1 | 1]);
    else st[id] = (st[id << 1] ^ st[id << 1 | 1]);
}

void update(int id, int l, int r, bool op, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, op ^ 1, i, val);
    update(id << 1 | 1, mid + 1, r, op ^ 1, i, val);
    if (!op) st[id] = (st[id << 1] | st[id << 1 | 1]);
    else st[id] = (st[id << 1] ^ st[id << 1 | 1]);
}

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1){
            res *= x;
        }
        x *= x;
        y /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int n1 = fastpow(2, n);
    for (int i = 1; i <= n1; ++i){
        cin >> a[i];
    }
    if (n & 1) build(1, 1, n1, 0);
    else build(1, 1, n1, 1);
    while (m--){
        ll l, r;
        cin >> l >> r;
        if (n & 1) update(1, 1, n1, 0, l, r);
        else update(1, 1, n1, 1, l, r);
        cout << st[1] << "\n";
    }
    return 0;
}