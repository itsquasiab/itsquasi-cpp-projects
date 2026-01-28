// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#define ll long long
#define ii pair<ll, ll>
// #define task ""

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

int n, m, a, b, c, d;

bool activated[arr];

vector<ii> nodes[arr];
int pre[arr];
ll dist[arr];

void distra(int s, ll ds[]){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i) ds[i] = LLONG_MAX, pre[i] = -1;
    ds[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        ll du = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (du != ds[u]) continue;
        for (auto e : nodes[u]){
            ll v = e.first;
            ll dv = e.second;
            if (ds[v] > dv + du){
                ds[v] = dv + du;
                pre[v] = u;
                pq.push({ds[v], v});    
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
    cin >> n >> m >> a >> b >> c >> d;
    for (int i = 1; i <= m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        nodes[u].push_back({v, w});
        nodes[v].push_back({u, w});
    }
    distra(a, dist);
    /*for (int i = b; i != -1; i = pre[i]){
        cout << i << "\n";
    }*/
    
    return 0;
}