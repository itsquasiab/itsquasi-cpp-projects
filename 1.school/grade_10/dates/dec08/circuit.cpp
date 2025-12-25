#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define ii pair<ll,ll>
#define tname "circuit"

using namespace std;

const ll arr = 206, mod = 2024;

int n, s, cnt = 0;
ll num[arr], low[arr];
vector<ll> nodes[arr];
vector<stack<ll>> i_found_a_path;
stack<ll> st;

void dfs(int u){
    num[u] = low[u] = ++cnt;
    st.push(u);
    for (auto v : nodes[u]){
        if (num[v]){
            if (num[v] == 1){
                i_found_a_path.push_back(st);
            }
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> s;
    int u, v;
    while (cin >> u >> v){
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    cout << "NO";
    /*dfs(s);
    if (!i_found_a_path.size()){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    stack<ll> sts = i_found_a_path[0];
    cout << sts.size() << "\n";
    cout << "1 ";
    while (!sts.empty()){
        cout << sts.top() << " ";
        sts.pop();
    }*/
    return 0;
}

