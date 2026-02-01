#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m, cmp, mxsz = 0;
int parent[arr], sz[arr];

int find_set(int v){
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        cmp--;
        mxsz = max(mxsz, sz[a]);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
    cmp = n;
    for (int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        union_set(a, b);
        cout << cmp << " " << mxsz << "\n";
    }
    return 0;
}
