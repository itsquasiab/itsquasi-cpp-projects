//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll parent[arr], sz[arr], mn[arr], mx[arr];

void make_set(ll v){
    parent[v] = v;
    sz[v] = 1;
    mn[v] = v;
    mx[v] = v;
}

ll find_set(ll v){
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        make_set(i);
    }
    while (m--){
        string s;
        int a, b;
        cin >> s;
        if (s == "union") cin >> a >> b, union_set(a, b);
        else{
            cin >> a;
            a = find_set(a);
            cout << mn[a] << " " << mx[a] << " " << sz[a] << "\n";
        }
    }
    return 0;
}