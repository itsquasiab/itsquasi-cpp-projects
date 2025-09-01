//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll parent[arr], sz[arr];

void make_set(ll v){
    parent[v] = v;
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
    
    return 0;
}