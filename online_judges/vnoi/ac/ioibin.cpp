//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll parent[arr], sz[arr];

void make_set(int p){
    parent[p] = p;
    sz[p] = 1;
}

int find_set(int p){
    return p == parent[p] ? parent[p] : parent[p] = find_set(parent[p]);
}

void union_sets(int a, int b){
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
    for (int i = 1; i <= 10000; ++i){
        make_set(i);
    }
    int p;
    cin >> p;
    while(p--){
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1){
            union_sets(x, y);
        }
        else {
            if(find_set(x) == find_set(y)) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}