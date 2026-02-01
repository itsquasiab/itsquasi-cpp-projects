// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int t, n, m;
vector<pair<ll, ll>> nodes[arr];
struct edgeinfo{
    int u, v;
    ll w;
    int p;
    int idx_u, idx_v;
};
vector<edgeinfo> edges;
ll d[arr];

void distra(int s, int n){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
    }
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        ll u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (auto i : nodes[u]){
            ll v = i.first;
            ll dv = i.second;
            if (dv + du < d[v]){
                d[v] = dv + du;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> t;
    while (t--){
        cin >> n >> m;

        edges.clear();
        vector<int> found;

        for (int i = 1; i <= m; ++i){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            nodes[u].push_back({v, w});
            nodes[v].push_back({u, w});
            int idx_u = nodes[u].size() - 1;
            int idx_v = nodes[v].size() - 1;
            edges.push_back({u, v, w, i, idx_u, idx_v});
        }
        distra(1, n);
        ll original_min = d[n];
        for (auto &e : edges){
            //cout << nodes[e.u][e.idx].first << " " << nodes[e.u][e.idx].second << "\n";
            nodes[e.u][e.idx_u].second += 2;
            nodes[e.v][e.idx_v].second += 2;

            distra(1, n);
            ll res = d[n];
            if (res - original_min == 1) found.push_back(e.p);

            nodes[e.u][e.idx_u].second -= 2;
            nodes[e.v][e.idx_v].second -= 2;
        }
        cout << found.size() << " ";
        if (!found.empty()){
            cout << "\n";
            for (auto i : found){
                cout << i << " ";
            }
        }
        
        for (int i = 1; i <= n; ++i){
            nodes[i].clear();
        }
        cout << "\n";
    }
    return 0;
}