#include <iostream>
#include <vector>
#define ll long long
#define tname "tjalg"

using namespace std;

const ll arr = 1e4 + 6, mod = 1e9 + 7;

int n, m, cnt = 0, res = 0;
vector<ll> node[arr];
ll low[arr], num[arr];

void tarjan(int u){
    low[u] = num[u] = ++cnt;
    for (auto v : node[u]){
        if (!num[v]) low[u] = min(low[u], num[v]);
        else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
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
        if (!num[i]) tarjan(i);
    }
    cout << res;
    return 0;
}



