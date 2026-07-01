// Minding my own business. :)
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<pair<ll, ll>> node[arr];
ll d[arr];
unordered_map<ll, ll> cnt;
int n, m;

void bfs()
{
    queue<pair<ll,ll>> q;
    q.push({1, 0});
    d[1] = 0;
    cnt[1] = 1;
    cnt[0] = 1;
    while (!q.empty())
    {
        int u = q.front().first;
        int du = q.front().second;
        q.pop();
        for (auto [to, w] : node[u])
        {
            int v = to;
            int dv = w;
            if (d[v] == du + dv) cnt[v] += cnt[u];
            if (d[v] > du + dv){
                d[v] = du + dv;
                q.push({v, d[v]});
                cnt[v] = cnt[u];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int k, u, v, l;
        cin >> k >> u >> v >> l;
        if (k == 2)
        {
            node[v].push_back({u, l});
        }
        node[u].push_back({v, l});
    }
    for (int i = 1; i <= n; ++i) d[i] = INT_MAX;
    bfs();
    cout << d[n] << " " << cnt[n];
    return 0;
}