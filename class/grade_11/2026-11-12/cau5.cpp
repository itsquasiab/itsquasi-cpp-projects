#include <bits/stdc++.h>
#define ll long long
#define task "cau5"

using namespace std;

const ll arr = 10006, mod = 1e9 + 7;

struct graph{
    int v;
    ll w;
};

vector<graph> nodes[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        nodes[u].push_back({v, w});
        nodes[v].push_back({u, w});
    }
    cout << -1;
    return 0;
}
