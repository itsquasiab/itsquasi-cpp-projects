#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<vector<ii>> node;
ll d1[arr], d2[arr];
int n, m;

void distra(const vector<vector<ii>>& node, int source, ll d[]){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
    }
    d[source] = 0;
    pq.push({0, source});
    while (pq.size()){
        int node1 = pq.top().second;
        ll dist1 = pq.top().first;
        pq.pop();
        if (dist1 != d[node1]) continue;
        for (int i = 0; i < node[node1].size(); ++i){
            ll dist2 = node[node1][i].first;
            int node2 = node[node1][i].second;
            if (d[node2] > dist1 + dist2){
                d[node2] = dist1 + dist2;
                pq.push({d[node2],node2});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    node.resize(n + 1);
    for (int i = 1; i <= m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({w, v});
        node[v].push_back({w, u});
    }
    distra(node, 1, d1);
    distra(node, n, d2);
    vector<ll> cities;
    ll for_comparison = d1[n];
    for (int i = 1; i <= n; ++i){
        if (d1[i] + d2[i] != for_comparison){
            cities.push_back(i);
        }
    }
    cout << cities.size() << "\n";
    for (auto i : cities){
        cout << i << "\n";
    }
    return 0;
}
