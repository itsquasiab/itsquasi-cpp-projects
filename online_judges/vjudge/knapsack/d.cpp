// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define task "d"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll fac[arr], invfac[arr];

ll pw(ll x, ll y){
    ll res = 1;
    x %= mod;
    while (y){
        if (y & 1){
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

ll modinv(ll x){
    return pw(x, mod - 2);
}

void precom(){
    fac[0] = 1;
    invfac[0] = 1;
    for (int i = 1; i < arr; ++i){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    invfac[arr - 1] = modinv(fac[arr - 1]);
    for (int i = arr - 2; i >= 0; --i){
        invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
    }
}

ll combination(ll n, ll k){
    if (k < 0 || k > n) return 0;
    return (fac[n] * invfac[k]) % mod * invfac[n - k] % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    precom();
    int h, w, n;
    cin >> h >> w >> n;
    ll dp[n + 5];
    pair<ll, ll> rc[n + 5];
    for (int i = 1; i <= n; ++i){
        cin >> rc[i].first >> rc[i].second;
    }
    n++;
    rc[n].first = h, rc[n].second = w;
    sort(rc + 1, rc + 1 + n);
    for (int i = 1; i <= n; ++i){
        dp[i] = combination(rc[i].first + rc[i].second - 2, rc[i].first - 1);
        for (int j = 1; j <= i - 1; ++j){
            if (rc[j].first <= rc[i].first && rc[j].second <= rc[i].second){
                ll ways = combination((rc[i].first - rc[j].first) + (rc[i].second - rc[j].second), rc[i].first - rc[j].first);
                dp[i] = (dp[i] - dp[j] * ways) % mod;
            }
        }
        dp[i] = (dp[i] + mod) % mod;
    }
    cout << dp[n];
    return 0;
}