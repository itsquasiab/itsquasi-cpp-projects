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

const ll arr = 1'000'006, mod = 1'000'000'007;

int n, m;
vector<pair<ll, ll>> nodes[arr];
ll dst[arr];

void distra(int s){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 1; i <= n; ++i) dst[i] = LLONG_MAX;
    dst[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        int nd1 = pq.top().second;
        ll dst1 = pq.top().first;
        pq.pop();
        if (dst1 != dst[nd1]) continue;
        for (auto v : nodes[nd1]){
            int nd2 = v.first;
            ll dst2 = v.second;
            if (dst1 + dst2 < dst[nd2]){
                dst[nd2] = dst1 + dst2;
                pq.push({dst[nd2], nd2});
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
        int u, v;
        ll w;
        cin >> u >> v >> w;
        nodes[u].push_back({v, w});
        //nodes[v].push_back({u, w});
    }
    distra(1);
    for (int i = 1; i <= n; ++i){
        cout << dst[i] << " ";
    }
    return 0;
}