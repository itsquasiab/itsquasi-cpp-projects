#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ii> node[arr];
ll d[arr];
ll pre[arr];
int n, m;
ll s, t;

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i) d[i] = LLONG_MAX;
    d[s] = 0;
    pre[s] = -1;
    pq.push({0, s});
    while (!pq.empty()){
        ll dist1 = pq.top().first, node1 = pq.top().second;
        pq.pop();
        if (dist1 != d[node1]) continue;
        for (int i = 0; i < node[node1].size(); ++i){
            ll dist2 = node[node1][i].first, node2 = node[node1][i].second;
            if (d[node2] > dist1 + dist2){
                d[node2] = dist1 + dist2;
                pre[node2] = node1;
                pq.push({d[node2], node2});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({w, v});
        node[v].push_back({w, u});
    }
    distra(s);
    cout << d[t] << "\n";
    vector<ll> go_back;
    for (ll v = t; v != 0; v = pre[v]){
        go_back.push_back(v);
        if (v == s) break;
    }
    reverse(go_back.begin(), go_back.end());
    for (auto i : go_back){
        cout << i;
        if (i != t) cout << " -> ";
    }
    return 0;
}

