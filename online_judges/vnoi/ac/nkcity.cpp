// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
ll par[arr], sz[arr];

struct edgelist
{
    ll u, v, t;
};

bool sorter(edgelist a, edgelist b){
    return a.t < b.t;
}

vector<edgelist> edges;

void build(int n){
    for (int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }
}

ll find(int u){
    return u == par[u] ? u : par[u] = find(par[u]);
}

bool join(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        ll u, v, t;
        cin >> u >> v >> t;
        edges.push_back({u, v, t});
    }
    sort(edges.begin(), edges.end(), sorter);
    build(n);
    ll res = 0;
    for (auto e : edges){
        if (!join(e.u, e.v)) continue;
        res = max(res, e.t);
    }
    cout << res;
    return 0;
}