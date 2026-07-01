//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll parent[arr];
ll sz[arr];

void make_set(int i){
    parent[i] = i;
    sz[i] = 1;
}

int find_set(int i){
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

map<ll, bool> leashed;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int m, t, p;
    cin >> m >> t >> p;
    for (int i = 1; i <= m; ++i) make_set(i);
    for (int i = 1; i <= t; ++i){
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }
    int res = 0;
    for (int i = 1; i <= p; ++i){
        int u;
        cin >> u;
        u = find_set(u);
        leashed[u] = 1;
    }
    for (int i = 1; i <= m; ++i){
        if (leashed[i]) res += sz[i];
    }
    cout << m - res;
    return 0;
}