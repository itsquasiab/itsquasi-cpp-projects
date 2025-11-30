#include<bits/stdc++.h>
#include <random>
#define ll long long

using namespace std;

const ll arr = 5006, mod = 1e9 + 7;

vector<ll> node[arr];
vector<ll> sz[arr];

unordered_map<ll, ll> kbc;

int n, m;
ll d[arr];

void bfs(){
    ll u, i, v;
    queue<ll> qu;
    qu.push(1);
    d[1] = 0;
    while(!qu.empty()){
        u = qu.front();
        //cout << u << " ";
        qu.pop();

        for (int i = 0; i < node[u].size(); ++i){
            ll v = node[u][i];
            //cout << u << " " << v << "\n";
            if (d[v] == 0){
                d[v] = d[u] + sz[u][i];
                qu.push(v);
                if (v == n) kbc[d[v]]++;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        ll k, u, v, l;
        cin >> k >> u >> v >> l;
        if (k == 2){
            node[v].push_back(u);
            sz[v].push_back(l);
        }
        node[u].push_back(v);
        sz[u].push_back(l);
    }
    bfs();
    cout << d[n] << " " << kbc[d[n]];
    return 0;
}
