//Minding my own business. :)
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll parent[arr], sz[arr];

void make_set(ll v){
    parent[v] = v;
    // By size
    sz[v] = 1;
    // By rank
    //sz[v] = 0;
}

ll find_set(ll v){
    /*if (v == parent[v]) return v;
    return find_set(parent[v]);*/
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        // By size
        sz[a] += sz[b];
        // By rank
        //if (sz[a] == sz[b]) sz[a]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        make_set(i);
    }
    while (m--){
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (s == "union") union_set(a, b);
        else{
            if (find_set(a) == find_set(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}