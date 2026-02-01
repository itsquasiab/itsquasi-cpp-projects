//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<int> node[arr];
int d[arr], par[arr];
bool vis[arr];

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : node[u]){
            if (!vis[v]){
                d[v] = d[u] + 1;
                par[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        ll a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    bfs(1);
    cout << d[n] << " " << par[n];
    return 0;
}