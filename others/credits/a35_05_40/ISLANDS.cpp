#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define pb push_back
#define se second
#define all(x) (x).begin(), (x).end()
template <class X, class Y> bool tmin(X &x, const Y &y) {

    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}


template <class X, class Y> bool tmax(X &x, const Y &y) {

    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}

const int maxN = 3e5 + 5;
int n, q;
vector<int> V[maxN];
int query[maxN];

namespace sub134 {
    void solve() {
        for (int qid = 1; qid <= q; ++qid) {
            int A = query[qid];
            int ans = 0;
            int node = 1;
            for (int i = 1; i <= n; ++i) {
                int cnt = V[i].end() - lower_bound(all(V[i]), A);
                if (ans <= cnt) {
                    ans = cnt;
                    node = i;
                }
            }
            cout << node << '\n';
        }
    }
}

namespace sub2 {
    int cnt[maxN][20];
    int cost[maxN];
    int ans[maxN];
    void solve() {
        for (int i = 1; i <= n; ++i) {
            for (int v : V[i]) ++cnt[i][v];
        }
        for (int v = 1; v <= 10; ++v) {
            int max_cost = 0;
            memset(cost, 0, (n + 1) * sizeof(int));
            for (int i = 1; i <= n; ++i) {
                for (int x = v; x <= 10; ++x) cost[i] += cnt[i][x];
                tmax(max_cost, cost[i]);
            }
            for (int i = n; i >= 1; --i) if (cost[i] == max_cost) {
                ans[v] = i;
                break;
            }
        }
        for (int qid = 1; qid <= q; ++qid) {
            int A = query[qid];
            cout << ans[A] << '\n';
        }
    }
}
void run_case() {
    cin >> n >> q;
    int max_val = 0, max_val_query = 0;
    for (int i = 1; i <= n; ++i) {
        int c; cin >> c;
        for (int j = 1; j <= c; ++j) {
            int v; cin >> v;
            tmax(max_val, v);
            V[i].pb(v);
        }
        sort(all(V[i]));
    }
    for (int i = 1; i <= q; ++i) {
        cin >> query[i];
        tmax(max_val_query, query[i]);
    }
    if (max(max_val, max_val_query) <= 10) return sub2::solve();
    return sub134::solve();
}

signed main() {
    #define task "ISLANDS"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int ntest = 1;
//    cin >> ntest;
    while (ntest--) run_case();
    return 0;
}

