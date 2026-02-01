#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define ll long long
#define ii pair<ll,ll>
#define tname "hight"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll parent[arr], sz[arr];
vector<ii> nodes[arr];
ll dist[arr];
ll pre[arr];
int n, m, s, t;

ll find_set(int i){
    return i == parent[i] ? i : parent[i] = find_set(parent[i]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void distra(int s){
    priority_queue<ii, vector<ii>, less<ii>> pq;
    for (int i = 1; i <= n; ++i) {
        dist[i] = LLONG_MIN;
    }
    dist[s] = LLONG_MAX;
    pq.push({LLONG_MAX, s});
    while(!pq.empty()){
        ll node1 = pq.top().second;
        ll dist1 = pq.top().first;
        pq.pop();
        if (dist1 != dist[node1]) continue;
        for (auto i : nodes[node1]){
            ll node2 = i.first;
            ll dist2 = i.second;
            if (min(dist1, dist2) > dist[node2]){
                dist[node2] = min(dist1, dist2);
                pre[node2] = node1;
                pq.push({dist[node2], node2});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        union_set(u, v);
        nodes[u].push_back({v, w});
        nodes[v].push_back({u, w});
    }
    if (find_set(s) != find_set(t)){
        cout << 0;
        return 0;
    }
    pre[s] = -1;
    distra(s);
    cout << dist[t] << "\n";
    vector<ll> path;
    for (int i = t; i != -1; i = pre[i]){
        if (i == -1) break;
        path.push_back(i);
    }
    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; --i){
        cout << path[i] << " ";
    }
    return 0;
}

