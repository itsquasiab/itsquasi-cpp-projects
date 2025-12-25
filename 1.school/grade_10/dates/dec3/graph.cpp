#include<iostream>
#include<vector>
#define ll long long
#define tname "graph"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ll> node[arr];
ll parent[arr];
ll num[arr], low[arr];
ll extra[arr];
ll n, m, cnt = 0;
ll tplt = 0;

void dfs(ll u){
    num[u] = low[u] = ++cnt;
    ll child = 0;
    for (auto v : node[u]){
        if (v == parent[u]) continue;
        if (num[v]){
            low[u] = min(low[u], num[v]);
        }
        else {
            parent[v] = u;
            child++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] != -1){
                if (low[v] >= num[u])
                    extra[u]++;
            }
        }
    }
    if (parent[u] == -1){
        if (child >= 2) extra[u] = child - 1;
        else if (child == 0) extra[u] = -1;
        else extra[u] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
        if (!num[i]){
            tplt++;
            parent[i] = -1;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << tplt + extra[i] << "\n";
    }
    return 0;
}
