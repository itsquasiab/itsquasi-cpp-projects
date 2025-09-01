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
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void update(int id, int l, int r, int i){
    if (i < l || r < i) return;
    if (l == r){
        st[id] ^= 1;
        return;
    }
    int mid = l + r >> 1;
    update(id << 1, l, mid, i);
    update(id << 1 | 1, mid + 1, r, i);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
int get(int id ,int l ,int r ,int k)
{
    if(st[id] < k) return -1;
    if(l == r) return l;
    int mid = l + r >> 1;
    int x = get(id << 1 , l ,mid , k);
    if(x  != -1) return x;
    return get(id << 1 | 1 ,mid + 1 , r ,k -st[id << 1]);
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
        ll u, v;
        cin >> u >> v;
        if (u == 1) update(1, 1, n, v);
        else cout << get(1, 1, n, v) << "\n";
    }
    return 0;
}