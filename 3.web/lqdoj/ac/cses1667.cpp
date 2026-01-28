#include <iostream>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n, m;
vector<ll> nodes[arr];
bool visited[arr];
queue<int> q;
int d[arr];
int par[arr];
vector<ll> ans;

void bfs(int s){
    q.push(s);
    visited[s] = 1;
    d[s] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();

        if (u == n) return;

        for (auto v : nodes[u]){
            if (!visited[v]){
                d[v] = d[u] + 1;
                par[v] = u;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    bfs(1);
    if (d[n] == 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << d[n] << "\n";
    for (int v = n; v != 0; v = par[v]){
        ans.push_back(v);
    }
    for (int i = ans.size() - 1; i >= 0; --i){
        cout << ans[i] << " ";
    }
    return 0;
}