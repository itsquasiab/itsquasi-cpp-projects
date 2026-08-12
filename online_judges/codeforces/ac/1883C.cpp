// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "1883C"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int tc;
    cin >> tc;
    while (tc--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n + 5, 0);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        if (k == 2 || k == 3 || k == 5){
            ll ans = k;
            ll res = 1e9;
            for (int i = 0; i < n; ++i){
                ll rem = a[i] % k;
                ll cost = (rem == 0) ? 0 : (k - rem);
                res = min(res, cost);
            }
            cout << res << "\n";
            continue;
        }
        if (k == 4){
            ll ans1 = k;
            ll cnt = 0;
            for (int i = 0; i < n; ++i){
                ll rem = a[i] % k;
                ll cost = (rem == 0) ? 0 : (k - rem);
                ans1 = min(ans1, cost);
                if (a[i] % 2 == 0) cnt += 1;
            }
            ll ans2 = max(0ll, 2 - cnt);
            cout << min(ans1, ans2) << "\n";
            continue;
        }
    }
    return 0;
}