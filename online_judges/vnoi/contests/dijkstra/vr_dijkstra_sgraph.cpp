#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#define ll long long
#define ii pair<ll, ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
struct nodeinfo{
    ll v, w;
};
vector<nodeinfo> n1[arr];
vector<nodeinfo> n2[arr];
ll d1[arr], d2[arr];

void distra(int s, ll d[], vector<nodeinfo> nodes[]){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
    }
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        ll du = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (du != d[u]) continue;
        for (auto e : nodes[u]){
            ll v = e.v;
            ll dv = e.w;
            if (d[v] > du + dv){
                d[v] = du + dv;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        n1[u].push_back({v, w});
        n2[v].push_back({u, w});
    }
    distra(1, d1, n1);
    distra(1, d2, n2);
    for (int i = 2; i <= n; ++i){
        if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX) cout << "-1\n";
        else cout << d1[i] + d2[i] << "\n";
    }
    return 0;
}
