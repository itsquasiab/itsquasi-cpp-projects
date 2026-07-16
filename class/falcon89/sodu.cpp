// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <map>
#include <set>
#define ll long long
#define task "sodu"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    map<ll, int> lf;
    for (int i = 1; i <= n; ++i){
        if (!lf.count(a[i])) lf[a[i]] = i;
    }
    set<ll> suf;
    ll res = 0;
    for (int i = n; i >= 1; --i){
        if (lf[a[i]] == i && !suf.empty()){
            ll val = a[i];

            auto its = suf.lower_bound(val);
            if (its != suf.begin()){
                --its;
                res = max(res, *its % val);
            }

            if (val >= 2){
                for (int mul = 2 * val; mul <= mx + val; mul += val) {
                    auto it = suf.lower_bound(mul);
                    if (it != suf.begin()){
                        --it;
                        if (*it >= mul - val){
                            res = max(res, *it % val);
                        }
                    }
                }
            }
        }
        suf.insert(a[i]);
    }
    cout << res;
    return 0;
}