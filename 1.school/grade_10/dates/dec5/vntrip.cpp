#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define tname "vntrip"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m, k;
vector<ii> node[arr];
ll dist[arr];
ll places[arr];

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        dist[i] = LLONG_MAX;
    }
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        ll node1 = pq.top().second;
        ll dist1 = pq.top().first;
        pq.pop();
        if (dist1 != dist[node1]) continue;
        for (int i = 0; i < node[node1].size(); ++i){
            ll node2 = node[node1][i].first;
            ll dist2 = node[node1][i].second;
            if (dist1 + dist2 < dist[node2]){
                dist[node2] = dist1 + dist2;
                pq.push({dist[node2], node2});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp", "r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) cin >> places[i];
    for (int i = 1; i <= m; ++i){
        ll u, v, d;
        cin >> u >> v >> d;
        node[u].push_back({v, d});
    }
    distra(1);
    ll sum = 0;
    for (int i = 1; i <= k; ++i){
        if (dist[places[i]] == LLONG_MAX){
            cout << -1;
            return 0;
        }
        sum += dist[places[i]];
        cout << dist[places[i]] << " ";
        distra(places[i]);
    }
    if (dist[1] == LLONG_MAX){
        cout << -1;
        return 0;
    }
    cout << dist[1] << " ";
    sum += dist[1];
    cout << sum;
    return 0;
}
