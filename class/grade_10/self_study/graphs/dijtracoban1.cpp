#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ii> node[arr];
ll dist[arr];
int n, m, s, t;

void distra(int source){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i) dist[i] = LLONG_MAX;
    dist[source] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (du != dist[u]) continue;

        for (auto i : node[u]){
            int v = i.first;
            int uv = i.second;
            if (dist[v] > du + uv){
                dist[v] = du + uv;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({v, w});
    }
    distra(s);
    if (dist[t] == LLONG_MAX) cout << -1;
    else cout << dist[t];
    return 0;
}
