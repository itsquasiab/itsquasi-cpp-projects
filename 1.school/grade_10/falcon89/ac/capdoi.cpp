//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k;
ll t = 0;
vector<ll> node[arr];
bool child[arr];

struct BIT {
    int n;
    vector<int> fenw;
    BIT(int n) : n(n), fenw(n+1, 0) {}

    void update(int i, int v) {
        for (; i <= n; i += i & -i)
            fenw[i] += v;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += fenw[i];
        return s;
    }

    int range(int l, int r) {
        if (l > r) return 0;
        if (l < 1) l = 1;
        if (r > n) r = n;
        return query(r) - query(l - 1);
    }
};

BIT bit(arr);

void dfs(int s){
    bit.update(s, 1);
    t += bit.range(s - k, s + k) - 1;
    for (int i = 0; i < node[s].size(); ++i){
        dfs(node[s][i]);
    }
    bit.update(s, -1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        child[v] = 1;
    }
    int root = 1;
    while (child[root]) root++;
    dfs(root);
    cout << t;
    return 0;
}