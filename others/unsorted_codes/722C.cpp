// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "722C"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
int x[arr];
bool flag[arr];

ll parent[arr], sz[arr];

void make(int v){
    parent[v] = v;
    sz[v] = a[v];
}

int find(int v){
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

void group(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], make(i);
    for (int i = 1; i <= n; ++i) cin >> x[i];
    vector<ll> res(n + 5);
    ll temp = 0;
    for (int i = n; i >= 1; --i){
        flag[x[i]] = 1;
        if (x[i] > 1 && flag[x[i] - 1]) group(x[i], x[i] - 1);    
        if (x[i] < n && flag[x[i] + 1]) group(x[i], x[i] + 1);
        temp = max(temp, sz[find(x[i])]);
        res[i - 1] = temp;
    }
    for (int i = 1; i <= n; ++i) cout << res[i] << "\n";
    return 0;
}