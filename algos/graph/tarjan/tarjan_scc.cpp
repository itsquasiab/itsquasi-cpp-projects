//Minding my own business. :)
//MADE BY ITSQUASI
#include<iostream>
#include<stack>
#include<vector>
#define ll long long

using namespace std;

const ll arr = 1e4 + 6, mod = 1e9 + 7;

ll depth[arr], low[arr];
bool in_stack[arr];
stack<ll> st;
vector<ll> node[arr];
vector<vector<ll>> scc;
int n, m, cnt = 0, res;

void tarjan(int u){
    depth[u] = low[u] = ++cnt;
    st.push(u);
    in_stack[u] = 1;
    for (auto v : node[u]){
        if (depth[v] && in_stack[v]) low[u] = min(low[u], depth[v]);
        else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (depth[u] == low[u]){
        vector<ll> comp;
        ll x;
        do {
            x = st.top();
            st.pop();
            in_stack[x] = 0;
            comp.push_back(x);
        } while (x != u);
        scc.push_back(comp);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
        if (depth[i] == 0) tarjan(i);
    }
    cout << "scc count: " << scc.size() << "\n";
    for (int i = 0; i < scc.size(); ++i){
        cout << "scc " << i + 1 << ": ";
        for (auto j : scc[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}
