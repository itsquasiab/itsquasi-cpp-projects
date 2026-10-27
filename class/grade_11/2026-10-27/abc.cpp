// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#include <numeric>
#include <map>
#define ll long long
#define task "abc"

using namespace std;

const ll arr = 2006, mod = 1e9 + 7;

pair<ll, ll> a[arr];

ll fac(int a){
    ll res = 1;
    for (int i = 2; i <= a; ++i) res *= i;
    return res;
}

ll calc (ll n, int k){
    if (k > n) return 0;
    if (k == n) return 1;
    return fac(n) / (fac(k) * fac(n - k));
}

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
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    sort (a + 1, a + 1 + n);
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        map<pair<ll, ll>, int> cnt;
        for (int j = i + 1; j <= n; ++j){
            ll x = a[j].first - a[i].first;
            ll y = a[j].second - a[i].second;
            ll gcdxy = gcd(x, y);
            x = x / gcdxy;
            y = y / gcdxy;
            cnt[{x, y}]++;
        }
        for (auto i : cnt){
            res += calc(i.second, 2);
        }
    }
    cout << res;
    return 0;
}