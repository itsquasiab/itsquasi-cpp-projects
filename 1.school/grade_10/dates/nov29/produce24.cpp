#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define tname "produce24"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m, k;
vector<ll> node[arr];
ll produce[arr];
ll pre[arr];
bool vis[arr];
ll maximum_sum = 0;
ll original_source = 0;

void dfs(int s){
    vis[s] = 1;
    bool f = 0;
    for (int cn = 0; cn < node[s].size(); ++cn){
        if (!vis[node[s][cn]]){
                //cout << "set node: " << node[s][cn] << "\n";
            pre[node[s][cn]] = s;
            f = 1;
            dfs(node[s][cn]);
            //cout << "done checking node: " << node[s][cn] << "\n";
        }
        //cout << "is this the final? " << f << "\n";
    }
    if (!f){
            vector<ll> path;
            for (int j = s; j != 0; j = pre[j]){
                path.push_back(produce[j]);
                //cout << j << " ";
                if (j == original_source) break;
            }
            sort(path.begin(), path.end(), greater<ll>());
            ll total_sum = 0;
            //cout << "- ";
            int actual_size = path.size();
            int final_size = min(k, actual_size);
            for (int j = 0; j < final_size; ++j){
                total_sum += path[j];
                //cout << path[j] << " ";
            }
            maximum_sum = max(maximum_sum, total_sum);
            //cout << ": " << maximum_sum << "\n";
        }
}

int main(){
    //ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp", "r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> produce[i];
    for (int i = 1; i <= m; ++i){
        ll u, v;
        cin >> u >> v;
        node[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
            //cout << "current config: " << i << "\n";
        if (!vis[i]){
            original_source = i;
            dfs(i);
        }
        for (int j = 1; j <= n; ++j){
            vis[j] = 0;
        }
    }
    cout << maximum_sum;
    return 0;
}
