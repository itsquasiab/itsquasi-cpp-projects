//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int parent[arr], sz[arr];

void make_set(int p){
    parent[p] = p;
    sz[p] = 1;
}

int find_set(int p){
    return p == parent[p] ? parent[p] : parent[p] = find_set(parent[p]);
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