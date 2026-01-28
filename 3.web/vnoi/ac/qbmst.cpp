// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

struct edge{
    int u, v;
    ll w;
};

vector<edge> edges;
vector<int> par;

int n, m;
ll res = 0;

void build(int n){
    par.resize(n + 5, 0);
    for (int i = 1; i <= n; ++i) par[i] = i;
}

int find(int u){
    return par[u] == u ? u : par[u] = find(par[u]);
}

bool join(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    par[v] = u;
    return 1;
}

bool sorter(edge u, edge v){
    return u.w < v.w;
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
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    build(n);
    sort(edges.begin(), edges.end(), sorter);

    for (auto e : edges){
        if (!join(e.u, e.v)) continue;
        res += e.w;
    }
    cout << res;
    return 0;
}