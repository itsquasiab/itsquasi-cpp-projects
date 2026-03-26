// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define ll long long
#define task "kquery"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

pair<ll, int> a[arr];
ll st[4 * arr];
int n, q;

struct qry{
    int i, j;
    ll k;
    int id;
} query[arr];

bool sorter_pair(pair<ll, int> a, pair<ll, int> b){
    return a.first > b.first;
}

bool sorter_query(qry a, qry b){
    return a.k > b.k;
}

void upd(int id, int l, int r, int p){
    if (l == r){
        st[id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid){
        upd(id << 1, l, mid, p);
    }
    else {
        upd(id << 1 | 1, mid + 1, r, p);
    }
    st[id] = st[id << 1] + st[id << 1 | 1];
}

ll get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
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
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n, sorter_pair);
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> query[i].i >> query[i].j >> query[i].k;
        query[i].id = i;
    }
    sort(query, query + q, sorter_query);
    vector<ll> res(q + 5);
    int ptr = 1;
    for (int i = 0; i < q; ++i){
        while (ptr <= n && a[ptr].first > query[i].k){
            upd(1, 1, n, a[ptr].second);
            ptr++;
        }
        res[query[i].id] = get(1, 1, n, query[i].i, query[i].j);
    }
    for (int i = 0; i < q; ++i){
        cout << res[i] << "\n";
    }
    return 0;
}