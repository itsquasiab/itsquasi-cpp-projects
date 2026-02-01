//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll st[4 * ARR];
ll a[ARR];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
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
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, ll val){
    if (st[id] < val) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (st[id << 1] >= val) return get(id << 1, l, mid, val);
    else return get(id << 1 | 1, mid + 1, r, val);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--){
        ll b;
        cin >> b;
        int pos = get(1, 1, n, b);
        if (pos == -1) cout << 0 << " ";
        else {
            cout << pos << " ";
            a[pos] -= b;
            update(1, 1, n, pos, a[pos]);
        }
    }
    return 0;
}