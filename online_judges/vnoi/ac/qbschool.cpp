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
vector<ii> nodes[arr];
ll d[arr], cnt[arr];

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i) d[i] = LLONG_MAX;
    d[s] = 0;
    cnt[s] = 1;
    pq.push({0, s});
    while (!pq.empty()){
        ll u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if (du != d[u]) continue;
        for (auto i : nodes[u]){
            ll v = i.first;
            ll dv = i.second;
            if (d[v] > dv + du){
                d[v] = dv + du;
                cnt[v] = cnt[u];
                pq.push({d[v], v});
            }
            else if (d[v] == dv + du){
                cnt[v] += cnt[u];
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
        int q, u, v;
        ll w;
        cin >> q >> u >> v >> w;
        if (q == 2){
            nodes[v].push_back({u, w});
        }
        nodes[u].push_back({v, w});
    }
    distra(1);
    cout << d[n] << " " << cnt[n] << "\n";
    return 0;
}