//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#define ll long long
#define ii pair<ll,ll>

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n, m, s, t;
ll a[arr];
ll temperature[arr];
vector<ii> nodes[arr];

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        temperature[i] = LLONG_MAX;
    }
    temperature[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        ll node1 = pq.top().second;
        ll dist1 = pq.top().first;
        pq.pop();
        if (dist1 != temperature[node1]) continue;
        for (auto i : nodes[node1]){
            ll node2 = i.first;
            ll dist2 = i.second;
            if (max(dist2, dist1) < temperature[node2]){
                temperature[node2] = max(dist2, dist1);
                pq.push({temperature[node2], node2});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        ll w = abs(a[v] - a[u]);
        nodes[u].push_back({v, w});
        nodes[v].push_back({u, w});
    }
    distra(s);
    cout << (temperature[t] == LLONG_MAX ? -1 : temperature[t]);
    return 0;
}