//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ii> node[arr];
ll pre[arr];
ll d[arr];
int n, m, s, t;

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
        pre[i] = -1;
    }
    d[s] = 0;
    pre[s] = -1;
    pq.push({0, s});
    while (!pq.empty()){
        ll node1 = pq.top().second;
        ll dist1 = pq.top().first;
        pq.pop();
        if (dist1 != d[node1]) continue;
        for (int i = 0; i < node[node1].size(); ++i){
            ll node2 = node[node1][i].second;
            ll dist2 = node[node1][i].first;
            if (d[node2] > dist2 + dist1){
                d[node2] = dist2 + dist1;
                pre[node2] = node1;
                pq.push({d[node2], node2});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({w, v});
        node[v].push_back({w, u});
    }
    distra(s);
    if (d[t] != LLONG_MAX){
    cout << d[t] << "\n";
    vector<ll> path;
    for (int i = t; i != -1; i = pre[i]){
        path.push_back(i);
        if (i == s) break;
    }
    reverse(path.begin(), path.end());
    for (auto i : path){
        cout << i << (i != t ? " -> " : "");
    }
    }
    else cout << -1;
    return 0;
}