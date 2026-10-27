// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
#define task "bedao_t1_kthsum"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll pf[arr];
ll bit[arr];
set<ll> set_distinct;
vector<ll> vals;
ll n, k;

void upd(int u, int v, int m){
    for (int i = u; i <= m; i += i & -i){
        bit[i] += v;
    }
}

ll get(int x){
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i){
        res += bit[i];
    }
    return res;
}

ll fcnt(ll x, int m){
    for (int i = 1; i <= m; ++i) bit[i] = 0;
    ll cnt = 0;
    
    int idx = lower_bound(vals.begin(), vals.end(), pf[0]) - vals.begin() + 1;
    upd(idx, 1, m);
    
    for (int j = 1; j <= n; ++j){
        ll target = pf[j] - x;
        int idx_tg = upper_bound(vals.begin(), vals.end(), target) - vals.begin();
        if (idx_tg > 0) cnt += get(idx_tg);
        idx = lower_bound(vals.begin(), vals.end(), pf[j]) - vals.begin() + 1;
        upd(idx, 1, m);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    pf[0] = 0;
    set_distinct.insert(0);
    for (int i = 1; i <= n; ++i){
        cin >> pf[i];
        pf[i] += pf[i - 1];
        set_distinct.insert(pf[i]);
    }
    for (auto i : set_distinct) vals.push_back(i);
    ll l = -1e14, r = 1e14, res = 0;
    while (l <= r){
        ll mid = l + (r - l) / 2;
        if (fcnt(mid, vals.size()) >= k){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res;
    return 0;
}