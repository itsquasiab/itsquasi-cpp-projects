// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define task "pwalk"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

vector<pair<ll, ll>> nodes[arr];
ll up[arr][12], depth[arr], dist[arr];

int n, q;

void dfs(int u, int p){
    up[u][0] = p;
    for (int k = 1; k <= 10; k++){
        up[u][k] = up[up[u][k - 1]][k - 1];
    }
    for (auto [v, w] : nodes[u]){
        if (v != p){
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + w;
            dfs(v, u);
        }
    }
}

ll lca(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);
    ll diff = depth[u] - depth[v];
    for (int k = 10; k >= 0; --k){
        if ((diff >> k) & 1){
            u = up[u][k];
        }
    }
    if (u == v) return u;
    for (int k = 10; k >= 0; --k){
        if (up[u][k] != up[v][k]){
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> q;
    for (int i = 1; i < n; ++i){
        ll a, b, l;
        cin >> a >> b >> l;
        nodes[a].push_back({b, l});
        nodes[b].push_back({a, l});
    }
    depth[1] = 0;
    dist[1] = 0;
    dfs(1, 0);
    while (q--){
        int u, v;
        cin >> u >> v;
        int x = lca(u, v);
        cout << dist[u] + dist[v] - 2 * dist[x] << "\n";
    }
    return 0;
}