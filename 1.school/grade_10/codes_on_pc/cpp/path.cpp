//path.cpp
#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e6;

int n, m;

ll parent[arr];
ll sz[arr];

void make_set(int i){
    parent[i] = i;
    sz[i] = 1;
}

ll find_set(int a){
    return a == parent[a] ? a : parent[a] = find_set(parent[a]);
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
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        make_set(i);
    }
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }
    ll t = 0;
    cout << min(sz[1], mod);
    return 0;
}
