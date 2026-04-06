#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<int> node[arr];
bool visited[arr];

int t = 0;
void dfs(int s){
    visited[s] = 1;
    for (auto i : node[s]){
            t++;
        if (!visited[i]) dfs(i);
    }
}

/*
3 3
1 2
2 3
3 2
*/

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
        if (!visited[i]){
            dfs(i);
        }
        memset(visited, 0, sizeof(visited));
    }
    cout << t;
    return 0;
}
