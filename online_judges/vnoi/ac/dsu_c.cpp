// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int par[arr], sz[arr];
ll cows[arr], lazy[arr];
int n, k;

int find(int v){
    if (v == par[v]) return v;
    int p = par[v];
    par[v] = find(p);
    lazy[v] += lazy[p];
    return par[v];
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        lazy[b] = cows[b] - cows[a];
    }
}

void add(int a, ll v){
    a = find(a);
    cows[a] += v;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }
    while (k--){
        string q;
        cin >> q;
        if (q == "join"){
            int u, v;
            cin >> u >> v;
            join(u, v);
        }
        else if (q == "add"){
            int u;
            ll w;
            cin >> u >> w;
            add(u, w);
        }
        else {
            int x, r;
            cin >> x;
            r = find(x);
            cout << lazy[x] + cows[r] << "\n";
        }
    }
    return 0;
}