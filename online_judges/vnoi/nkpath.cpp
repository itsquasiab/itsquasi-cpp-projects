// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#define ll long long
#define task "nkpath"

using namespace std;

const ll arr = 106, mod = 1e9;

ll a[arr][arr], dp[arr][arr];

vector<ll> primefac(ll x){
    vector<ll> primes;
    int d = 2;
    while (d * d <= x){
        if (x % d == 0){
            primes.push_back(d);
            while (x % d == 0) x /= d;
        }
        d++;
    }
    if (x > 1) primes.push_back(x);
    return primes;
}

unordered_map<ll, ll> sumdp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) dp[i][1] = 1;
    for (int j = 1; j <= n; ++j){
        for (int i = 1; i <= m; ++i){
            for (int prev_i = 1; prev_i < i; ++prev_i) {
                if (gcd(a[prev_i][j], a[i][j]) > 1) {
                    dp[i][j] = (dp[i][j] + dp[prev_i][j]) % mod;
                }
            }
            if (j > 1) {
                vector<ll> p = primefac(a[i][j]);
                ll ways = 0;
                for (int mask = 1; mask < (1 << p.size()); ++mask){
                    ll prod = 1;
                    int k = 0;
                    for (int idx = 0; idx < p.size(); ++idx){
                        if ((mask >> idx) & 1) prod *= p[idx], ++k;
                    }
                    if (k & 1) ways = (ways + sumdp[i][prod]) % mod;
                    else ways = (ways - sumdp[i][prod] + mod) % mod;
                }
                dp[i][j] = (dp[i][j] + ways) % mod;
            }

            vector<ll> p = primefac(a[i][j]);
            for (int mask = 1; mask < (1 << p.size()); ++mask){
                ll prod = 1;
                for (int idx = 0; idx < p.size(); ++idx){
                    if ((mask >> idx) & 1) prod *= p[idx];
                }
                for (int next_i = i; next_i <= m; ++next_i){
                    sumdp[next_i][prod] = (sumdp[next_i][prod] + dp[i][j]) % mod;
                }
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= m; ++i) res = (res + dp[i][n]) % mod;
    cout << res;
    return 0;
}