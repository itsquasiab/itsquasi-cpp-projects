#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <set>
#define ll long long
#define task "safenet2"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;
int n, m;
vector<pair<int, int>> nodes[arr];
ll num[arr], low[arr], cnt = 0, res = 1;
stack<pair<int, int>> st;

void tarjan(int u, int p_edge){
    num[u] = low[u] = ++cnt;
    for (auto e : nodes[u]){
        int v = e.first;
        int id = e.second;
        if (id == p_edge) continue;
        if (num[v] != 0){
            if (num[v] < num[u]) {
                low[u] = min(low[u], num[v]);
                st.push({u, v});
            }
        }
        else {
            st.push({u, v});
            tarjan(v, id);
            low[u] = min(low[u], low[v]);

            if (low[v] >= num[u]) {
                set<int> bcc;
                while (true) {
                    auto edge = st.top();
                    st.pop();
                    bcc.insert(edge.first);
                    bcc.insert(edge.second);
                    if (edge.first == u && edge.second == v) break;
                }
                res = max(res, (ll)bcc.size());
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        nodes[u].push_back({v, i});
        nodes[v].push_back({u, i});
    }
    for (int i = 1; i <= n; ++i){
        if (!num[i]) tarjan(i, -1);
    }
    cout << res;
}
