#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<vector<ii>> node1;
vector<vector<ii>> nodeR;
ll d[arr];
int n, m;
priority_queue<ii, vector<ii>, greater<ii>> pq;

void distra(const vector<vector<ii>>& node, int source){
    for (int i = 1; i <= n * 2; ++i){
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
    node1.resize(n + 1);
    nodeR.resize(n + 1);
    for (int i = 1; i <= m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        node1[u].push_back({w, v});
        //create an opposite node
        nodeR[v].push_back({w, u});
    }
    //connect all the node with the opposite node
    /*for (int i = 1; i <= n; ++i){
        node[i].push_back({0, i + n});
        //node[i + n].push_back({0, i});
    }*/
    distra(node1, 1);
    for (int i = 1; i <= n; ++i){
        if (d[i] < LLONG_MAX){
            pq.push({d[i], i});
        }
    }
    while (pq.size()){
        int node1 = pq.top().second;
        ll dist1 = pq.top().first;
        pq.pop();
        if (dist1 != d[node1]) continue;
        for (int i = 0; i < nodeR[node1].size(); ++i){
            ll dist2 = nodeR[node1][i].first;
            int node2 = nodeR[node1][i].second;
            if (d[node2] > dist1 + dist2){
                d[node2] = dist1 + dist2;
                pq.push({d[node2],node2});
            }
        }
    }
    for (int i = 2; i <= n; ++i){
        if (d[i] == LLONG_MAX) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    return 0;
}
