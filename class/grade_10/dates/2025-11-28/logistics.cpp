#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ii> node[arr];
ll d[arr];
int n, m;
ll s, x, t;

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i) d[i] = LLONG_MAX;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        ll dist1 = pq.top().first, node1 = pq.top().second;
        pq.pop();
        if (dist1 != d[node1]) continue;
        for (int i = 0; i < node[node1].size(); ++i){
            ll dist2 = node[node1][i].first, node2 = node[node1][i].second;
            if (d[node2] > dist1 + dist2){
                d[node2] = dist1 + dist2;
                pq.push({d[node2], node2});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s >> x >> t;
    for (int i = 1; i <= m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({w, v});
        node[v].push_back({w, u});
    }
    distra(s);
    ll sum = d[x];
    if (sum == LLONG_MAX){
        cout << -1;
        return 0;
    }
    distra(x);
    if (d[t] == LLONG_MAX){
        cout << -1;
        return 0;
    }
    cout << sum + d[t];
    return 0;
}

