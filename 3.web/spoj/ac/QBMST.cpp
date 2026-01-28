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
struct EDGE{
    ll u, v, w;
};
vector<EDGE> edges;
bool sorter(EDGE a, EDGE b){
    return a.w < b.w;
}
ll find(ll v){
    return v == par[v] ? v : par[v] = find(par[v]);
}
bool merge(ll a, ll b){
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
    for (int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), sorter);
    ll res = 0;
    for (auto e : edges){
        if (!merge(e.u, e.v)) continue;
        res += e.w;
    }
    cout << res;
    return 0;
}