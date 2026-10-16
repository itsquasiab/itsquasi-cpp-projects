// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "356A"

using namespace std;

const ll arr = 3e5 + 6, mod = 1e9 + 7;

ll parent[arr], sz[arr], res[arr];

void build(int v){
    parent[v] = v;
    sz[v] = 1;
    res[v] = 0;
}

int find(int v){
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        res[b] = a;
    }
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
    parent[n + 1] = n + 1;
    while (m--){
        int l, r, x;
        cin >> l >> r >> x;
        int cur = find(l);
        while (cur <= r){
            if (cur == x) cur = find(cur + 1);
            else{
                res[cur] = x;
                parent[cur] = find(cur + 1);
                cur = parent[cur];
            }
            //cout << cur << "\n";
        }
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << " ";
    return 0;
}