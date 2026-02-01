//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<int> node[arr];
int d[arr], par[arr];
bool vis[arr];

void dfs_rec(int s){
    vis[s] = 1;
    
    for (int v : node[s]){
        if (!vis[v])
            d[v] = d[s] + 1;
            par[v] = s;
            dfs_rec(v);
    }
}

void dfs_stack(int s){
    stack<int> st;
    st.push(s);

    while(!st.empty()){
        int u = st.top();
        st.pop();
        if (!vis[u]){
            vis[u] = 1;
            for (int i = node[u].size() - 1; i >= 0; --i) {
                int v = node[u][i];
                if (!vis[v])
                    d[v] = d[u] + 1;
                    par[v] = u;
                    st.push(v);
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
    dfs_rec(1);
    cout << d[n] << " " << par[n];
    return 0;
}