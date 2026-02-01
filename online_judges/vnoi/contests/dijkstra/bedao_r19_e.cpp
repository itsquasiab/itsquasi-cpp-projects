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

const ll arr = 1'000'006, mod = 1'000'000'007;

int n, m;
struct nodeinfo
{
    ll v, w, h;
};
vector<nodeinfo> nodes[arr];
ll d[arr], df[arr];

struct nm{
    ll d, mx, mn, node;
    bool operator<(const nm& other) const {
        return d > other.d;
    }
};

void distra(int s){
    priority_queue<nm> pq;
    for (int i = 1; i <= n; ++i){
        d[i] = LLONG_MAX;
        df[i] = LLONG_MIN;
    }
    d[s] = 0;
    df[s] = 0;
    pq.push({0, LLONG_MIN, LLONG_MAX, s});
    while (!pq.empty()){
        ll du = pq.top().d;
        ll u = pq.top().node;
        ll mxu = pq.top().mx;
        ll mnu = pq.top().mn;
        ll dfu = mxu - mnu;
        pq.pop();
        if (du > d[u]) continue;
        if (du == d[u] && dfu < df[u]) continue;
        for (auto e : nodes[u]){
            ll v = e.v;
            ll dv = e.w;
            ll hv = e.h;
            ll nd = du + dv;
            ll mxv = max(mxu, hv);
            ll mnv = min(mnu, hv);
            ll ndf = mxv - mnv;
            if ((d[v] > nd) || (nd == d[v] && ndf > df[v])){
                d[v] = nd;
                df[v] = ndf;
                pq.push({d[v], mxv, mnv, v});
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
        ll u, v, w, h;
        cin >> u >> v >> w >> h;
        nodes[u].push_back({v, w, h});
        nodes[v].push_back({u, w, h});
    }
    distra(1);
    cout << df[n];
    return 0;
}
