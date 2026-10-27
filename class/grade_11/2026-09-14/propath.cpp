#include <iostream>
#include <vector>
#define ll long long
#define task "propath"

using namespace std;

const ll arr = 1e5 + 6, mod = 20240131;

ll c[arr];

vector<ll> paths[arr];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
        res += c[i];
    }
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }
    cout << res;
    return 0;
}