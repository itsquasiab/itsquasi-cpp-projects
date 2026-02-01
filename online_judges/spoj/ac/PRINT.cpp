// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <climits>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ll> segmented_sieve(ll l, ll r){
    ll sqrtr = sqrt(r);
    vector<bool> mark(sqrtr + 1, 0);
    vector<ll> primes;
    for (ll i = 2; i <= sqrtr; ++i){
        if (!mark[i]){
            primes.push_back(i);
            for (ll j = i * i; j <= sqrtr; j += i) mark[j] = 1;
        }
    }

    vector<bool> isprime(r - l + 1, 1);
    for (ll i : primes)
        for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i){
            isprime[j - l] = 0;
        }
    if (l == 1) isprime[0] = 0;

    vector<ll> res;
    for (ll i = 0; i < (ll)isprime.size(); ++i)
        if (isprime[i])
            res.push_back(l + i);
    
    return res;
}
int n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    while (n--){
        ll l, r;
        cin >> l >> r;
        vector<ll> isprime = segmented_sieve(l, r);
        for (auto p : isprime) cout << p << "\n";
    }
    return 0;
}