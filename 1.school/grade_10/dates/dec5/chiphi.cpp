#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define tname "chiphi"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m, s, t, w;
struct graphing{
    ll v, d, c;
};
vector<graphing> node[arr];
ll dist[arr];

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
            ll node2 = node[node1][i].v;
            ll dist2 = node[node1][i].d;
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
    cin >> n >> m >> s >> t >> w;
    for (int i = 1; i <= m; ++i){
        ll u, v, c, d;
        cin >> u >> v >> d >> c;
        node[u].push_back({v, d, c});
        node[v].push_back({u, d, c});
    }
    distra(s);
        long double sum = dist[t] + w;
        cout << fixed << setprecision(2) << sum;
    return 0;
}
