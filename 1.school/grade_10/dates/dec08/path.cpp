#include <iostream>
#include <vector>
#define ll long long
#define tname "path"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll parent[arr], sz[arr];
vector<ll> nodes[arr];
ll pre[arr];
bool visited[arr];
int n, m, s, t;

ll find_set(int i){
    return i == parent[i] ? i : parent[i] = find_set(parent[i]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void dfs(int u){
    visited[u] = 1;
    for (auto v : nodes[u]){
        if (!visited[v]){
            pre[v] = u;
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        union_set(u, v);
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    if (find_set(s) != find_set(t)){
        cout << -1;
        return 0;
    }
    pre[s] = -1;
    dfs(s);
    vector<ll> path;
    for (int i = t; i != -1; i = pre[i]){
        if (i == -1) break;
        path.push_back(i);
    }
    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; --i){
        cout << path[i] << " ";
    }
}

