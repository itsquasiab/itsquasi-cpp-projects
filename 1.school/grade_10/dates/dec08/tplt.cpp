#include <iostream>
#define ll long long
#define tname "tplt"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll parent[arr], sz[arr];
int n, m;

ll find_set(int i){
    return i == parent[i] ? i : parent[i] = find_set(parent[i]);
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
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
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
    int t = 0;
    for (int i = 1; i <= n; ++i){
        if (i == find_set(i)) t++;
    }
    cout << t;
}
