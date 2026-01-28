//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 7;

ll a[ARR], st[4 * ARR], lazy[4 * ARR];

void push(int id, int l, int r){
    if (lazy[id]){
        st[id] = (r - l + 1) - st[id];
        if (l != r){
            lazy[id << 1] ^= 1;
            lazy[id << 1 | 1] ^= 1;
        }
        lazy[id] ^= 1;
    }
}

void update(int id, int l, int r, int u, int v){
    push(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        lazy[id] ^= 1;
        push(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, u, v);
    update(id << 1 | 1, mid + 1, r, u, v);
    st[id] = (st[id << 1] + st[id << 1 | 1]);
}

ll get(int id, int l, int r, int i){
    push(id, l, r);
    if (st[id] < i) return -1;
    if (l == r) return l;
    int mid = l + r >> 1;
    ll x = get(id << 1, l, mid, i);
    if (x != -1) return x;
    else return get(id << 1 | 1, mid + 1, r, i - st[id << 1]);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    while (q--){
        ll l, u, v, x;
        cin >> l;
        if (l == 1){
            cin >> u >> v;
            update(1, 1, n, u, v);
        }
        else {
            cin >> x;
            cout << get(1, 1, n, x) << "\n";
        }
    }
    return 0;
}