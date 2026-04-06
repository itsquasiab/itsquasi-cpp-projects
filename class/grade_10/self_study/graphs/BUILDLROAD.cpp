#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll parent[arr];
ll sz[arr];

void make_set(int s){
    parent[s] = s;
    sz[s] = 1;
}

ll find_set(int s){
    return s == parent[s] ? s : parent[s] = find_set(parent[s]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (a > b) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) make_set(i);
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }
    vector<pair<ll,ll>> conn;
    ll temp = -1;
    for (int i = 1; i <= n; ++i){
        if (i == find_set(i)){
            if (temp != -1) conn.push_back({temp, i});
            temp = i;
        }
    }
    cout << conn.size() << "\n";
    for (auto i : conn){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
