// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "hn_hsg9_25_muahang"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll b[arr];
int n, m;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    vector<ll> dp(n + 1, 1e18);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i){
        if (a[i] == 1) dp[i] = b[i];
    }
    for (int k = 2; k <= m; ++k){
        vector<ll> ml(n + 2, 1e18), mr(n + 2, 1e18);
        ll val = 1e18;
        for (int i = 1; i <= n; ++i){
            if (a[i] == k - 1){
                val = min(val, dp[i] - i);
            }
            ml[i] = val;
        }
        val = 1e18;
        for (int i = n; i >= 1; --i){
            if (a[i] == k - 1){
                val = min(val, dp[i] + i);
            }
            mr[i] = val;
        }
        vector<ll> newdp(n + 1, 1e18);
        for (int i = 1; i <= n; ++i){
            if (a[i] == k){
                ll left = i + ml[i];
                ll right = mr[i] - i;
                newdp[i] = b[i] + min(left, right);
            }
        }
        dp = newdp;
    }
    ll res = 1e18;
    for (int i = 1; i <= n; ++i){
        if (a[i] == m) res = min(res, dp[i]);
    }
    cout << res;
    return 0;
}
