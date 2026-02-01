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
ll parent[arr], sz[arr];

struct EDGE
{
    int u, v;
    ll w;
};
vector<EDGE> edges;

bool sorter(EDGE u, EDGE v){
    return u.w < v.w;
}

ll find(int v){
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

ll join(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
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
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), sorter);
    ll res = 0;
    for (auto i : edges){
        if (join(i.u, i.v)) res += i.w;
    }
    cout << res;
    return 0;
}