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
int parent[arr], sz[arr];

struct edgelist{
    int u, v, w;
};
vector<edgelist> edges;

bool sorter(edgelist a, edgelist b){
    return a.w < b.w;
}

int find(int v){
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = parent[a];
        sz[a] += sz[b];
        return 1;
    }
    return 0;
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
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    ll res = 0;
    sort(edges.begin(), edges.end(), sorter);
    for (auto i : edges)
    {
        if (merge(i.u, i.v)) res += i.w;
    }
    cout << res;
    return 0;
}