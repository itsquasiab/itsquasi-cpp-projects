// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll par[arr], sz[arr];

ll find(int v){
    return v == par[v] ? v : par[v] = find(par[v]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i) par[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1){
            merge(x, y);
        }
        else {
            if (find(x) != find(y)) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
    }
    return 0;
}