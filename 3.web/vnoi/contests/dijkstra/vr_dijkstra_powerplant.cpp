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

int n, m, k;
vector<ll> nodes[arr];
ll d[arr], b[arr];

priority_queue<ii> q;

ll best[arr];

void multi_bfs(){
    while (!q.empty()){
        ll r = q.top().first;
        ll p = q.top().second;
        q.pop();
        if (r < best[p]) continue;
        if (r == 0) continue;
        for (auto v : nodes[p]){
            if (r - 1 > best[v]){
                best[v] = r - 1;
                q.push({r - 1, v});
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
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        best[i] = -1;
    }
    for (int i = 1; i <= m; ++i){
        ll u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    for (int i = 1; i <= k; ++i){
        int p, r;
        cin >> p >> r;
        if (r > best[p]){
            best[p] = r;
            q.push({r, p});
        }
    }
    multi_bfs();
    for (int i = 1; i <= n; ++i){
        cout << (best[i] < 0 ? 0 : 1);
    }
    return 0;
}