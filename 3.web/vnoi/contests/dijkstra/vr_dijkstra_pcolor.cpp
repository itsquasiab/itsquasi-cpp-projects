#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#define ll long long
#define ii pair<ll, ll>

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, l, r, c, st, en;
vector<ll> nodes[arr];
ll d[arr];
int cl[arr];
bool used[arr];

void distra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
    }
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        ll du = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (du != d[u]) continue;
        if (u == en) break;

        if (u < n && d[u + 1] > du + r){
            d[u + 1] = du + r;
            pq.push({d[u + 1], u + 1});
        }

        if (u > 1 && d[u - 1] > du + l){
            d[u - 1] = du + l;
            pq.push({d[u - 1], u - 1});
        }

        int color = cl[u];
        if (!used[color]){
            used[color] = 1;
            for (auto v : nodes[color]){
                if (d[v] > du + c){
                    d[v] = du + c;
                    pq.push({d[v], v});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> l >> r >> c >> st >> en;
    for (int i = 1; i <= n; ++i){
        int c1;
        cin >> c1;
        nodes[c1].push_back(i);
        cl[i] = c1;
        used[c1] = 0;
    }
    distra(st);
    cout << d[en];
    return 0;
}
