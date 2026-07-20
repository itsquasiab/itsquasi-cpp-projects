// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define ll long long
#define task "lc_ts10_26_d"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n, m;
vector<pair<ll, ll>> rng;

bool found(ll range, ll startpos, ll endpos){
    ll bots = 1;
    ll i = startpos;
    int j = 0;
    while (j < m){
        ll i2 = i + range;
        if (i2 <= rng[j].second) {
            bots++;
            i = max(i2, rng[j].first);
        }
        else{
            j++;
            if (j < m && i2 <= rng[j].second){
                bots++;
                i = max(i2, rng[j].first);
            }
        }
        if (bots == n) break;
    }
    return bots == n;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    ll startpos = 1e18, endpos = -1e18;
    for (int i = 1; i <= m; ++i){
        ll x, y;
        cin >> x >> y;
        startpos = min(startpos, x);
        endpos = max(endpos, y);
        rng.push_back({x, y});
    }
    sort(rng.begin(), rng.end());
    ll l = 0, r = endpos, res = 0;
    while (l <= r){
        ll mid = (l + r) >> 1;
        if (found(mid, startpos, endpos)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res;
    return 0;
}