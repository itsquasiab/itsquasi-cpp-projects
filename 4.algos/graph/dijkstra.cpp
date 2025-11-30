//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, int>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, inf = LLONG_MAX;

vector<ii> node[arr];
ll d[arr], pre[arr];
int n, m, s;

void dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = inf;
        pre[i] = -1;
    }
    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        ll du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (du != d[u]) continue; // bỏ các trạng thái cũ

        for (auto [v, w] : node[u]) {
            if (d[v] > du + w) {
                d[v] = du + w;
                pre[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        node[u].push_back({v, w});
        node[v].push_back({u, w});
    }
    dijkstra(s);
    for (int i = 1; i <= n; ++i){
        if (d[i] == inf) cout << "no path to " << i << "\n";
        else cout << s << " -> " << i << " = " << d[i] << "\n";
    }
    /*
    vector<ll> path;
    for (int i = t; i != 0; i = pre[i]){
        path.push_back(i);
        if (i == s) break;
    }
    reverse(path.begin(), path.end());
    for (auto i : path){
        cout << i << (i != t ? " -> " : "");
    }
    */
    return 0;
}