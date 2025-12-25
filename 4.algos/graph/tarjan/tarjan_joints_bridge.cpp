//Minding my own business. :)
//MADE BY ITSQUASI
#include<iostream>
#include<vector>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll depth[arr], low[arr];
vector<ll> node[arr];
vector<vector<ll>> scc;
bool arti[arr];          // articulation point
int n, m, cnt = 0, arti_points = 0, bridges = 0;

vector<ll> group_arti_points;     // list of articulation points
vector<pair<ll,ll>> group_bridges; // list of bridges (u, v)

void tarjan(int u, int parent){
    depth[u] = low[u] = ++cnt;
    int child = 0;
    for (auto v : node[u]){
        if (v == parent) continue;
        if (depth[v]) low[u] = min(low[u], depth[v]);
        else {
            tarjan(v, u);
            child++;
            low[u] = min(low[u], low[v]);
            if(parent != u && low[v] >= depth[u]) arti[u] = 1;
            if (low[v] > depth[u]) {
                bridges++;
                group_bridges.push_back({u, v});
            }
        }
    }
    if (parent == u && child >= 2) arti[u] = 1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
        if (depth[i] == 0) tarjan(i, i);
    }
    for (int i = 1; i <= n; ++i){
        if (arti[i]) {
            arti_points++;
            group_arti_points.push_back(i);
        }
    }
    cout << "articulation point count: " << arti_points << "\n";
    for (auto x : group_arti_points) cout << x << " ";
    cout << "\nbridge count: " << bridges << "\n";
    for (auto x : group_bridges) cout << x.first << "-" << x.second << " ";
    cout << "\n";
}