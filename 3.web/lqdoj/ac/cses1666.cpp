#include <iostream>
#include <vector>
#include <utility>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
ll parent[arr], sz[arr];
vector<pair<ll,ll>> con;

ll find_set(int v){
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }
    int saved = -1;
    for (int i = 1; i <= n; ++i){
        if (i == find_set(i)){
            if (saved == -1) saved = i;
            else {
                con.push_back({saved, i});
                saved = i;
            }
        }
    }
    cout << con.size() << "\n";
    for (auto i : con){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
