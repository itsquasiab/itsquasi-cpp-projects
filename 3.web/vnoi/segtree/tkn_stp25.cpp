//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], st[4 * ARR];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

void update(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}
int get(int id, int l, int r, int x, int i)
{
    if (st[id] < x || r < i ) return -1;
    if (l == r) return l;
    int mid = l + r >> 1;
    ll g = get(id << 1, l, mid, x, i);
    if (g != -1) return g;
    else return get(id << 1 | 1, mid + 1, r, x, i);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build (1, 1, n);
    while (q--){
        ll l;
        cin >> l;
        if (l == 1){
            ll i, x;
            cin >> i >> x;
            update(1, 1, n, i, x);
        }
        else {
            ll x, i;
            cin >> x >> i;
            cout << get(1, 1, n, x, i) << "\n";
        }
    }
    return 0;
}