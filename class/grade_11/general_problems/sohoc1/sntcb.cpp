// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define task "sntcb"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool mark[arr];

vector<ll> primes;

int sumdg(ll n){
    int t = 0;
    while (n){
        t += n % 10;
        n /= 10;
    }
    return t;
}

void sieve(){
    mark[1] = mark[0] = 1;
    for (int i = 2; i * i <= 1e6; ++i){
        for (int j = i * i; j <= 1e6; j += i) mark[j] = 1;
    }
    for (int i = 2; i <= 1e6; ++i){
        if (!mark[i]) primes.push_back(i);   
    }
}

ll segmented_sieve(ll n){
    if (n <= 5) return 5;
    ll l = n, r = n + 5000;
    vector<bool> is_prime(r - l + 1, 1);
    for (auto p : primes){
        if (p * p > r) break;
        ll start = ((l + p - 1) / p) * p;
        if (start < p * p) start = p * p;
        for (ll j = start; j <= r; j += p){
            is_prime[j - l] = 0;
        }
    }
    for (ll x = l; x <= r; ++x){
        if (is_prime[x - l] && sumdg(x) % 5 == 0) return x;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    sieve();
    ll n;
    cin >> n;
    cout << segmented_sieve(n);
    return 0;
}