//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

struct iamlazy{
    ll add;
    ll inc;
};

ll a[ARR], st[ARR * 4];
iamlazy lazy[ARR * 4];

ll sum(ll a, ll d, ll n){
    return n * a + n * d * (n - 1) / 2;
}

void push(int id, int l, int r){
    if (lazy[id].add || lazy[id].inc){
        int len = r - l + 1;
        st[id] += sum(lazy[id].add, lazy[id].inc, len);
        if (l != r){
            int mid = l + r >> 1, left = mid - l + 1;
            lazy[id << 1].add += lazy[id].add;
            lazy[id << 1 | 1].add += lazy[id].add + lazy[id].inc * left;
            lazy[id << 1].inc += lazy[id].inc;
            lazy[id << 1 | 1].inc += lazy[id].inc;
        }
        lazy[id].add = lazy[id].inc = 0;
    }
}

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void update(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        ll ss = l - u + 1;
        lazy[id].add += ss;
        lazy[id].inc += 1;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, v);
    update(id << 1 | 1, mid + 1, r, u, v);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

ll get(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = l + r >> 1;
    ll g1 = get(id << 1, l, mid, u, v);
    ll g2 = get(id << 1 | 1, mid + 1, r, u, v);
    return g1 + g2;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    while (k--){
        int l, u, v;
        cin >> l >> u >> v;
        if (l == 1) update(1, 1, n, u, v);
        else cout << get(1, 1, n, u, v) << "\n";
    }
    return 0;
}
