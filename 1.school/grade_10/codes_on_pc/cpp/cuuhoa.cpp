#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ii> node[arr];
ll dist[arr];
ll cnt[arr];
int n, m, s, t;

void distra(int source){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        dist[i] = LLONG_MAX;
        cnt[i] = 0;
    }
    dist[source] = 0;
    cnt[source] = 1;
    pq.push({0, source});

    while (!pq.empty()){
        ll dist1 = pq.top().first;
        ll node1 = pq.top().second;
        pq.pop();

        if (dist1 != dist[node1]) continue;

        for (auto i : node[node1]){
            ll node2 = i.first;
            ll dist2 = i.second;

            if (dist[node2] > dist1 + dist2){
                dist[node2] = dist1 + dist2;
                cnt[node2] = cnt[node1];
                pq.push({dist[node2], node2});
            }
            else if (dist[node2] == dist1 + dist2){
                cnt[node2] = cnt[node2] + cnt[node1];
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
        node[v].push_back({u, w});
    }
    distra(s);
    if (dist[t] == LLONG_MAX) cout << "-1\n-1";
    else cout << dist[t] << "\n" << cnt[t];
    return 0;
}
