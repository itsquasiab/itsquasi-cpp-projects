// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#define ll long long
#define ii pair<ll, ll>
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, m;
struct nodeinfo
{
    ll v, w, b;
};
vector<nodeinfo> nodes[arr];
ll d[arr], b[arr];

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
        b[i] = 0;
    }
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        ll du = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (du != d[u]) continue;
        for (auto i : nodes[u]){
            ll v = i.v;
            ll dv = i.w;
            ll bv = i.b;
            if (d[v] > du + dv){
                d[v] = du + dv;
                b[v] = b[u] + bv;
                pq.push({d[v], v});
            }
            else if (d[v] == du + dv){
                b[v] = max(b[v], b[u] + bv);
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
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        ll u, v, w, b;
        cin >> u >> v >> w >> b;
        nodes[u].push_back({v, w, b});
        nodes[v].push_back({u, w, b});
    }
    distra(1);
    if (d[n] == LLONG_MAX) cout << -1;
    else cout << d[n] << " " << b[n];
    return 0;
}