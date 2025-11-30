//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll parent[arr], sz[arr];

void make_set(int i){
    parent[i] = i;
    sz[i] = 1;
}

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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) make_set(i);
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        union_set(u, v);
        if (sz[find_set(1)] == n){
            cout << i;
            return 0;
        }
    }
    cout << "FAILURE";
    return 0;
}