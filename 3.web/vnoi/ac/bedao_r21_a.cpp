//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

bool prime[arr];
vector<ll> primes;

void sieve(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i){
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i < arr; ++i){
        if (!prime[i]) primes.push_back(i);
    }
}

ll pow8(ll x){
    return x * x * x * x * x * x * x * x;
}

bool div9(ll x){
    for (int i = 0; i < primes.size() && primes[i] <= 177; ++i){
        if (pow8(primes[i]) == x) return 1;
    }
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= x; ++i){
        ll p = primes[i];
        if (x % (p * p) == 0){
            ll q2 = x / (p * p);
            ll q = sqrt(q2);
            if (q * q == q2 && q > 1 && q != p && !prime[q]) return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    int n;
    cin >> n;
    while (n--){
        ll a;
        cin >> a;
        cout << (div9(a) ? "YES" : "NO") << "\n";
    }
    return 0;
}