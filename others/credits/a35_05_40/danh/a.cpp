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

const int maxN = 1e5 + 5;
int n, s[maxN], p[maxN];

#define get_bit(x, i) (((x) >> (i)) & 1ll)
namespace sub1 {
    vector<int> V[maxN];

    void solve() {
        int ans = 0;
        for (int sub = 0; sub < (1 << n); ++sub) {
            int total_f = 0;
            vector<int> cur;
            for (int i = 1; i <= n; ++i) if (get_bit(sub, i)) {
                total_f += s[i];
                cur.pb(s[i]);
            }
            V[total_f].pb(sub);
            for (int subb : V[total_f]) {
                if ((subb & sub) == 0) {
                    int mx1 = 0, mx2 = 0;
                    for (int i = 1; i <= n; ++i) if (get_bit(subb, i)) tmax(mx1, p[s[i]]);
                    for (int v : cur) tmax(mx2, p[v]);
                    tmax(ans, abs(mx1 - mx2));
                }
            }
        }
        cout << ans;
    }
}
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        tmax(p[s[i]], v);
    }
   return sub1::solve();
}

signed main() {
    #define task "a"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int ntest = 1;
//    cin >> ntest;
    while (ntest--) run_case();
    return 0;
}

/*
a.inp:
8
4 7 3 8 5 6 9 2
15 3 20 11 8 30 6 25
a.out:
24
*/