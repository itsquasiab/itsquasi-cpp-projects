// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <set>
#define ll long long
#define task "volleyball"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];

set<ll> sums;

/*bool find_pos(ll target, int pos){
    int l = 1, r = 1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (b[pos] + b)
    }
}*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    sort(b + 1, b + 1 + m);
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            sums.insert(a[i] + a[j]);
        }
    }
    ll res = 0;
    for (auto sum : sums){
        for (int i = 1; i <= m; ++i){
            ll target = sum - b[i]; // find the target
            int j = lower_bound(b + 1, b + 1 + m, target) - b;
            //cout << b[i] << " " << b[j] << " " << b[i] + b[j] << "\n";
            if (target == b[j]){
                //cout << "found: " << sum << "\n";
                if (b[j] == b[i]){
                    int k = upper_bound(b + 1, b + 1 + m, target) - b;
                    int len = k - j;
                    //cout << "duplicate found: " << len << "\n";
                    if (len == 1) continue;
                }
                res = sum;
                break;
            }
            if (res) break;
        }
        if (res) break;
    }
    if (res) cout << res;
    else cout << "no volleyball today";
    return 0;
}