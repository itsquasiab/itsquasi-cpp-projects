// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

vector<pair<ll, ll>> a;

vector<bool> sieve(ll l, ll r){
    ll sr = sqrt(r);
    vector<bool> mark(sr + 1, 0);
    vector<ll> primes;
    for (ll i = 2; i <= sr; ++i){
        if (!mark[i]){
            primes.push_back(i);
            for (ll j = i * i; j <= sr; j += i) mark[j] = 1;
        }
    }
    vector<bool> isprime(r - l + 1, 1);
    for (ll i : primes){
        for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i){
            isprime[j - l] = 0;
        }
    }
    if (l == 1) isprime[0] = 0;
    return isprime;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int n;
    cin >> n;
    ll lmn = LLONG_MAX, rmx = LLONG_MIN;
    while (n--){
        ll l, r;
        cin >> l >> r;
        a.push_back({l, r});
        lmn = min(lmn, l);
        rmx = max(rmx, r);
    }
    vector<bool> isprime = sieve(lmn, rmx);
    vector<ll> pref(isprime.size() + 1, 0);
    for (int i = 0; i < isprime.size(); ++i){
        pref[i + 1] = pref[i] + isprime[i];
    }
    for (auto i : a){
        cout << pref[i.second - lmn + 1] - pref[i.first - lmn] << '\n';
    }
    return 0;
}