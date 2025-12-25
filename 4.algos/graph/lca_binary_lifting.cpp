//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<int> adj[arr];
int up[20][arr];
int depth[arr];
int n, q;

void dfs(int v, int p) {
    up[0][v] = p;
    for (int u : adj[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int k = 0; k < 20; k++) {
        if (diff & (1 << k))
            u = up[k][u];
    }

    if (u == v) return u;

    for (int k = 20 - 1; k >= 0; k--) {
        if (up[k][u] != up[k][v]) {
            u = up[k][u];
            v = up[k][v];
        }
    }

    return up[0][u];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 1;
    depth[root] = 0;
    dfs(root, root);

    for (int k = 1; k < 20; k++) {
        for (int v = 1; v <= n; v++) {
            up[k][v] = up[k - 1][ up[k - 1][v] ];
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}