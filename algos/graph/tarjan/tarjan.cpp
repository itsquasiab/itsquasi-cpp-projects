//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <stack>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n, m;
vector<ll> node[arr];
stack<ll> st;
ll num[arr], low[arr];
ll cnt = 0;

void dfs(int u){
    num[u] = low[u] = ++cnt;
    st.push(u);
    for (int i = 0; i < node[u].size(); ++i){
        int v = node[u][i];
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
        if (!num[i]) dfs(i);
    }
    for (int i = 1; i <= n; ++i){
        cout << i << ": " << num[i] << " | " << low[i] << "\n";
    }
    return 0;
}