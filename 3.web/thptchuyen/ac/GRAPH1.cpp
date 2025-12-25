//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
vector<ll> nodes[arr];
bool visited[arr];
ll len[arr];

void dfs(int u){
    visited[u] = 1;
    for (auto v : nodes[u]){
        if (!visited[v]){
            len[v] = len[u] + 1;
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    dfs(1);
    for (int i = 2; i <= n; ++i){
        cout << len[i] << "\n";
    }
    return 0;
}