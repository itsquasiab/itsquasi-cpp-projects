#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define tname "vntour"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
vector<ii> node[arr];
ll dist_to_n[arr];
ll dist_to_1[arr];

void distra(int s, ll dist[]){
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
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        ll u, v, d;
        cin >> u >> v >> d;
        node[u].push_back({v, d});
        node[v].push_back({u, d});
    }
    distra(1, dist_to_n);
    distra(n, dist_to_1);
    ll comparison = dist_to_n[n];
    vector<ll> currently_on_vacation;
    for (int i = 2; i < n; ++i){
        if (dist_to_n[i] + dist_to_1[i] != comparison) currently_on_vacation.push_back(i);
    }
    cout << currently_on_vacation.size() << "\n";
    for (auto i : currently_on_vacation){
        cout << i << "\n";
    }
    return 0;
}

