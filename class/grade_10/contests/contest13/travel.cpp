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

vector<pair<ll, ll>> nodes[arr];
ll d[arr];
int n, q;

void distra(int s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
    }
    d[s] = 1;
    pq.push({d[s], s});
    while (!pq.empty()){
        ll du = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (du != d[u]) continue;
        for (auto i : nodes[u]){
            ll v = i.first;
            ll dv = i.second;
            if (du + dv + 1 < d[v]){
                d[v] = du + dv + 1;
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
    cin >> n >> q;
    for (int i = 1; i < n; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        nodes[u].push_back({v, w});
        nodes[v].push_back({u, w});
    }
    ll past = 0;
    vector<ll> saves[n + 5];
    bool seen[n + 5] = {0};
    while (q--){
        ll u, v;
        cin >> u >> v;
        if (!seen[u]){
            distra(u);
            for (int i = 1; i <= n; ++i){
                saves[u].push_back(d[i]);
            }
            seen[u] = 1;
        }
        cout << saves[u][v - 1] << "\n";
    }
    return 0;
}