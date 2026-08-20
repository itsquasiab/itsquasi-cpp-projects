#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define pb push_back
#define se second
#define all(x) (x).begin(), (x).end()
template <class X, class Y> bool tmin(X &x, const Y &y) {

    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}


template <class X, class Y> bool tmax(X &x, const Y &y) {

    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}

const int maxN = 1e5 + 5;

int n, q, up[maxN][__lg(maxN) + 5], dep[maxN];
vector<int> adj[maxN];

#define get_bit(x, i) (((x) >> (i)) & 1ll)
set<int> leaf;
void dfs(int u) {
    if (adj[u].size() == 1 && u != 1) leaf.insert(u);
    for (int v : adj[u]) if (v != up[u][0]) {
        dep[v] = dep[u] + 1;
        up[v][0] = u;
        for (int i = 1; (1 << i) <= n; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
        dfs(v);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; (1 << i) <= k; ++i) if (get_bit(k, i)) u = up[u][i];
    if (u == v) return u;
    for (int j = __lg(dep[u]); j >= 0; --j) {
        if (up[v][j] != up[u][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int s;

void run_case() {
    cin >> s >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        ++u;
        ++v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    while (q--) {
        int u, v; cin >> u >> v;
        ++u;
        ++v;
        cout << dis(u, v) << '\n';
    }
}

signed main() {
    #define task "PATROL"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int ntest = 1;
//    cin >> ntest;
    while (ntest--) run_case();
    return 0;
}


