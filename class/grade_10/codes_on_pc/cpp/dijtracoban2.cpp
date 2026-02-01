#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ii> node[arr];
ll d[arr];
int n, m;

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i) d[i] = LLONG_MAX;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (du != d[u]) continue;

        for (auto i : node[u]){
            int v = i.first;
            int uv = i.second;
            if (d[v] > du + uv){
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({v, w});
    }
    distra(1);
    for (int i = 2; i <= n; ++i){
        cout << (d[i] == LLONG_MAX ? 1000000000 : d[i]) << " ";
    }
    return 0;
}
