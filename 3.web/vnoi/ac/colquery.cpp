//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int parent[arr];
int sz[arr];
int n, m;
vector<unordered_map<ll,ll>> color_map;

void make_set(int i, int c){
    parent[i] = i;
    color_map[i][c] = 1;
    sz[i] = 1;
}

ll find_set(int i){
    return parent[i] == i ? i : parent[i] = find_set(parent[i]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        for (auto p : color_map[b]) {
            color_map[a][p.first] += p.second;
        }
        sz[a] += sz[b];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    color_map.resize(n + 1);
    for (int i = 1; i <= n; ++i){
        int c;
        cin >> c;
        make_set(i, c);
    }
    for (int i = 1; i <= m; ++i){
        int q;
        cin >> q;
        if (q == 1){
            int u, v;
            cin >> u >> v;
            union_set(u, v);
        }
        else {
            int u, c;
            cin >> u >> c;
            u = find_set(u);
            cout << color_map[u][c] << "\n";
        }
    }
    return 0;
}