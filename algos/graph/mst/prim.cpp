// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define ll long long
#define ii pair<ll, ll>
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
vector<ii> nodes[arr];

ll dist[arr];

ll prim(int s){
    int res = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i) dist[i] = LLONG_MAX;

    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        ll du = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (du != dist[u]) continue;

        res += dist[u]; dist[u] = LLONG_MIN;
        for (auto e : nodes[u]){
            ll v = e.first;
            ll dv = e.second;
            if (dist[v] > dv){
                dist[v] = dv;
                pq.push({dist[v], v});
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u].push_back({v, w});
        nodes[v].push_back({u, w});
    }

    cout << prim(1) << '\n';
    return 0;
}