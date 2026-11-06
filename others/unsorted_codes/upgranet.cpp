// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "upgranet"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll parent[arr], sz[arr], bandwidth[arr];

void build(int v){
    parent[v] = v;
    sz[v] = 1;
    bandwidth[v] = 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) build(i);
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
    }
    return 0;
}