// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <stack>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

vector<ll> node[arr];
ll parent[arr];
ll num[arr], low[arr];
int extra[arr];
int n, m, cnt = 0;
int nodes = 0;
int edge = 0;

void dfs(int u)
{
    num[u] = low[u] = ++cnt;
    int child = 0;

    for (int v : node[u])
    {
        if (v == parent[u]) continue;

        if (num[v]) {
            low[u] = min(low[u], num[v]);
        }
        else {
            parent[v] = u;
            dfs(v);
            child++;

            low[u] = min(low[u], low[v]);

            // bridge
            if (low[v] > num[u])
                edge++;

            // articulation point
            if (parent[u] == 0) {
                if (child >= 2) extra[u] = 1;
            }
            else if (low[v] >= num[u]) {
                extra[u] = 1;
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
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!num[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (extra[i]) nodes++;
    }
    cout << nodes << " " << edge;
    return 0;
}