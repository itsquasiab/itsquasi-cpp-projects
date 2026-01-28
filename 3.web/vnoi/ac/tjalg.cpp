// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <stack>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m, cnt = 0, res = 0;
vector<int> nodes[arr];
int depth[arr], low[arr];
bool in_stack[arr];
stack<int> st;

void tarjan(int u){
    depth[u] = low[u] = ++cnt;
    st.push(u);
    in_stack[u] = 1;
    for (auto v : nodes[u]){
        if (!depth[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v]){
            low[u] = min(low[u], depth[v]);
        }
    }
    if (depth[u] == low[u]){
        res++;
        while (1)
        {
            int v = st.top();
            st.pop();
            in_stack[v] = 0;
            if (v == u) break;
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
        if (depth[i] == 0) tarjan(i);
    }
    cout << res;
    return 0;
}